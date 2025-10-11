# Docker Configuration Reference

## Overview

The QR Menu Generator uses a multi-container Docker setup with optimized images for production deployment. This document details the Docker configuration, build processes, and deployment strategies.

## Container Architecture

### Service Composition

```yaml
services:
  postgres:     # PostgreSQL 15 database
  backend:      # Spring Boot API server
  frontend:     # React app with Nginx
```

### Network Configuration

All services communicate through a custom bridge network:
```yaml
networks:
  qr-menu-network:
    driver: bridge
    name: qr-menu-network
```

### Volume Management

Persistent storage for database data:
```yaml
volumes:
  postgres_data:
    name: qr-menu-postgres-data
```

## Backend Container (Spring Boot)

### Dockerfile Analysis

```dockerfile
# Build stage with full Maven and JDK
FROM maven:3.9.5-eclipse-temurin-17-alpine AS builder
WORKDIR /app
COPY pom.xml .
RUN mvn dependency:go-offline -B
COPY src ./src
RUN mvn clean package -DskipTests -B
RUN java -Djarmode=layertools -jar target/*.jar extract --destination target/extracted

# Runtime stage with minimal JRE
FROM eclipse-temurin:17-jre-alpine
RUN addgroup -g 1001 -S appgroup && \
    adduser -u 1001 -S appuser -G appgroup
WORKDIR /app
RUN mkdir -p /app/data && chown -R appuser:appgroup /app
COPY --from=builder --chown=appuser:appgroup /app/target/*.jar app.jar
USER appuser
EXPOSE 8080
ENTRYPOINT ["java", "-XX:+UseContainerSupport", "-XX:MaxRAMPercentage=75.0", "-jar", "app.jar"]
```

### Build Optimization Features

1. **Multi-stage Build**: Separates build dependencies from runtime
2. **Layer Caching**: Dependencies downloaded separately for better caching
3. **Non-root User**: Runs as dedicated user for security
4. **JVM Optimization**: Container-aware memory management
5. **Minimal Base Image**: Alpine Linux for smaller image size

### Environment Variables

```bash
# Database Configuration
SPRING_PROFILES_ACTIVE=docker
SPRING_DATASOURCE_URL=jdbc:postgresql://postgres:5432/qrmenudb
SPRING_DATASOURCE_USERNAME=qrmenu_user
SPRING_DATASOURCE_PASSWORD=qrmenu_password
SPRING_DATASOURCE_DRIVER_CLASS_NAME=org.postgresql.Driver
SPRING_JPA_DATABASE_PLATFORM=org.hibernate.dialect.PostgreSQLDialect
SPRING_JPA_HIBERNATE_DDL_AUTO=update

# Application Configuration
APP_BASE_URL=${APP_BASE_URL:-http://localhost}
FRONTEND_URL=${FRONTEND_URL:-http://localhost}
```

### Health Monitoring

The backend exposes health endpoints:
```bash
# Health check endpoint
GET /actuator/health

# Response
{
  "status": "UP",
  "components": {
    "db": {"status": "UP"},
    "ping": {"status": "UP"}
  }
}
```

## Frontend Container (React + Nginx)

### Dockerfile Analysis

```dockerfile
# Build stage with Node.js
FROM node:18.19-alpine3.19 AS builder
RUN apk add --no-cache python3 make g++
WORKDIR /app
COPY package*.json ./
RUN npm ci --only=production --no-audit --no-fund && npm cache clean --force
RUN npm ci --include=dev --no-audit --no-fund
COPY . .
RUN npm run build

# Runtime stage with Nginx
FROM nginx:alpine
COPY --from=builder /app/dist /usr/share/nginx/html
COPY nginx.conf /etc/nginx/nginx.conf
EXPOSE 8080
CMD ["nginx", "-g", "daemon off;"]
```

### Build Optimization Features

1. **Multi-stage Build**: Separates build tools from runtime server
2. **Dependency Caching**: npm dependencies cached separately
3. **Production Build**: Optimized Vite production build
4. **Static Asset Serving**: Efficient Nginx static file serving
5. **Custom Configuration**: Tailored nginx.conf for SPA routing

### Nginx Configuration

```nginx
events {
    worker_connections 1024;
}

http {
    include /etc/nginx/mime.types;
    default_type application/octet-stream;

    # Gzip compression
    gzip on;
    gzip_vary on;
    gzip_min_length 1024;
    gzip_proxied expired no-cache no-store private auth;
    gzip_types
        application/javascript
        application/json
        text/css
        text/plain
        text/xml;

    # Upstream backend configuration
    upstream backend {
        server backend:8080;
        server 127.0.0.1:8080 backup;
    }

    server {
        listen 8080;
        server_name _;
        root /usr/share/nginx/html;
        index index.html;

        # API proxy to backend
        location /api/ {
            proxy_pass http://backend/api/;
            proxy_http_version 1.1;
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto $scheme;
        }

        # SPA routing support
        location / {
            try_files $uri $uri/ /index.html;
            
            # Security headers
            add_header X-Frame-Options "SAMEORIGIN" always;
            add_header X-Content-Type-Options "nosniff" always;
            add_header X-XSS-Protection "1; mode=block" always;
            add_header Referrer-Policy "strict-origin-when-cross-origin" always;
        }

        # Static asset caching
        location ~* \.(js|css|png|jpg|jpeg|gif|ico|svg|woff|woff2|ttf|eot)$ {
            expires 1y;
            add_header Cache-Control "public, immutable";
            access_log off;
        }
    }
}
```

## Database Container (PostgreSQL)

### Configuration

```yaml
postgres:
  image: postgres:15-alpine
  environment:
    - POSTGRES_DB=qrmenudb
    - POSTGRES_USER=qrmenu_user
    - POSTGRES_PASSWORD=${DB_PASSWORD}
  volumes:
    - postgres_data:/var/lib/postgresql/data
  restart: unless-stopped
```

### Security Features

1. **Custom User**: Non-default database user
2. **Environment Variables**: Passwords via environment variables
3. **Volume Persistence**: Data survives container restarts
4. **Network Isolation**: Only accessible within Docker network
5. **Regular Updates**: Uses official PostgreSQL images with security updates

### Backup Strategy

```bash
# Database backup
docker-compose exec postgres pg_dump -U qrmenu_user qrmenudb > backup.sql

# Database restore
docker-compose exec -T postgres psql -U qrmenu_user -d qrmenudb < backup.sql
```

## Docker Compose Configuration

### Development Configuration

```yaml
version: '3.8'

services:
  postgres:
    image: postgres:15-alpine
    environment:
      - POSTGRES_DB=qrmenudb
      - POSTGRES_USER=qrmenu_user
      - POSTGRES_PASSWORD=qrmenu_password
    volumes:
      - postgres_data:/var/lib/postgresql/data
    ports:
      - "5432:5432"

  backend:
    build:
      context: ./backend
      dockerfile: Dockerfile
    ports:
      - "8080:8080"
    environment:
      - SPRING_PROFILES_ACTIVE=docker
      - APP_BASE_URL=http://localhost
    depends_on:
      - postgres

  frontend:
    build:
      context: ./frontend
      dockerfile: Dockerfile
    ports:
      - "80:8080"
    depends_on:
      - backend
```

### Production Configuration

```yaml
version: '3.8'

services:
  postgres:
    image: postgres:15-alpine
    environment:
      - POSTGRES_DB=qrmenudb
      - POSTGRES_USER=qrmenu_user
      - POSTGRES_PASSWORD=${DB_PASSWORD}
    volumes:
      - postgres_data:/var/lib/postgresql/data
    restart: unless-stopped
    networks:
      - qr-menu-network

  backend:
    image: bansikah/qr-menu-backend:latest
    environment:
      - SPRING_PROFILES_ACTIVE=docker
      - APP_BASE_URL=${APP_BASE_URL}
      - FRONTEND_URL=${FRONTEND_URL}
    depends_on:
      - postgres
    restart: unless-stopped
    networks:
      - qr-menu-network

  frontend:
    image: bansikah/qr-menu-frontend:latest
    ports:
      - "80:8080"
    depends_on:
      - backend
    restart: unless-stopped
    networks:
      - qr-menu-network
```

## Image Registry

### Docker Hub Images

The application images are published to Docker Hub:

- **Backend**: `bansikah/qr-menu-backend:latest`
- **Frontend**: `bansikah/qr-menu-frontend:latest`

### Image Sizes

Optimized multi-stage builds result in minimal image sizes:
- Backend: ~200MB (JRE + JAR)
- Frontend: ~50MB (Nginx + static files)

### Tagging Strategy

```bash
# Version tagging
docker tag bansikah/qr-menu-backend:latest bansikah/qr-menu-backend:v1.0.0

# Environment tagging
docker tag bansikah/qr-menu-backend:latest bansikah/qr-menu-backend:production
```

## Build Commands

### Local Development Build

```bash
# Build all services
docker-compose build

# Build specific service
docker-compose build backend
docker-compose build frontend

# Build with no cache
docker-compose build --no-cache
```

### Production Build and Push

```bash
# Build for production
docker build -t bansikah/qr-menu-backend:latest ./backend
docker build -t bansikah/qr-menu-frontend:latest ./frontend

# Push to registry
docker push bansikah/qr-menu-backend:latest
docker push bansikah/qr-menu-frontend:latest

# Pull in production
docker pull bansikah/qr-menu-backend:latest
docker pull bansikah/qr-menu-frontend:latest
```

## Container Management

### Service Control

```bash
# Start all services
docker-compose up -d

# Stop all services
docker-compose down

# Restart specific service
docker-compose restart backend

# View service logs
docker-compose logs -f backend

# Execute commands in containers
docker-compose exec backend bash
docker-compose exec postgres psql -U qrmenu_user -d qrmenudb
```

### Resource Monitoring

```bash
# Container resource usage
docker stats

# Container processes
docker-compose top

# Network information
docker network ls
docker network inspect qr-menu-network
```

### Cleanup Commands

```bash
# Remove stopped containers
docker container prune

# Remove unused images
docker image prune

# Remove unused volumes
docker volume prune

# Complete cleanup
docker system prune -a
```

## Security Considerations

### Container Security

1. **Non-root Users**: All containers run as non-root users
2. **Minimal Images**: Alpine-based images with minimal attack surface
3. **No Secrets in Images**: Credentials via environment variables
4. **Regular Updates**: Base images updated regularly
5. **Network Isolation**: Services communicate only within Docker network

### Production Hardening

```bash
# Security scan
docker scan bansikah/qr-menu-backend:latest

# Vulnerability assessment
docker run --rm -v /var/run/docker.sock:/var/run/docker.sock \
  aquasec/trivy image bansikah/qr-menu-backend:latest
```

## Troubleshooting

### Common Issues

1. **Port conflicts**: Check for conflicting services on ports 80, 8080, 5432
2. **Memory issues**: Increase Docker memory limits if containers are killed
3. **Network issues**: Verify Docker network configuration
4. **Volume permissions**: Check file permissions on mounted volumes

### Debug Commands

```bash
# Check container status
docker-compose ps

# View detailed logs
docker-compose logs --details

# Inspect container configuration
docker inspect qr-menu-backend

# Check network connectivity
docker-compose exec backend ping postgres
docker-compose exec frontend curl backend:8080/api/restaurants
```