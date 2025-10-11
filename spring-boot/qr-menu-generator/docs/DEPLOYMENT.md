# Production Deployment Guide

## Prerequisites

### Server Requirements
- Ubuntu 20.04 LTS or similar Linux distribution
- 2GB RAM minimum (4GB recommended)
- 20GB disk space minimum
- Open ports 80 and 443
- Docker and Docker Compose installed

### Domain Setup
- Domain name pointing to server IP
- SSL certificate (recommended: Let's Encrypt)
- DNS A record configured

## Installation Steps

### 1. Server Preparation

```bash
# Update system packages
sudo apt update && sudo apt upgrade -y

# Install Docker
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Install Docker Compose
sudo curl -L "https://github.com/docker/compose/releases/latest/download/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose

# Add user to docker group
sudo usermod -aG docker $USER
```

### 2. Application Deployment

```bash
# Create application directory
mkdir -p /opt/qr-menu-generator
cd /opt/qr-menu-generator

# Create docker-compose.yml file
cat > docker-compose.yml << 'EOF'
version: '3.8'

services:
  postgres:
    image: postgres:15-alpine
    container_name: qr-menu-postgres
    environment:
      - POSTGRES_DB=qrmenudb
      - POSTGRES_USER=qrmenu_user
      - POSTGRES_PASSWORD=${DB_PASSWORD}
    volumes:
      - postgres_data:/var/lib/postgresql/data
    ports:
      - "127.0.0.1:5432:5432"
    networks:
      - qr-menu-network
    restart: unless-stopped

  backend:
    image: bansikah/qr-menu-backend:latest
    container_name: qr-menu-backend
    ports:
      - "127.0.0.1:8080:8080"
    environment:
      - SPRING_PROFILES_ACTIVE=docker
      - SPRING_DATASOURCE_URL=jdbc:postgresql://postgres:5432/qrmenudb
      - SPRING_DATASOURCE_USERNAME=qrmenu_user
      - SPRING_DATASOURCE_PASSWORD=${DB_PASSWORD}
      - SPRING_DATASOURCE_DRIVER_CLASS_NAME=org.postgresql.Driver
      - SPRING_JPA_DATABASE_PLATFORM=org.hibernate.dialect.PostgreSQLDialect
      - SPRING_JPA_HIBERNATE_DDL_AUTO=update
      - APP_BASE_URL=${APP_BASE_URL}
      - FRONTEND_URL=${FRONTEND_URL}
    depends_on:
      - postgres
    networks:
      - qr-menu-network
    restart: unless-stopped

  frontend:
    image: bansikah/qr-menu-frontend:latest
    container_name: qr-menu-frontend
    ports:
      - "80:8080"
    depends_on:
      - backend
    networks:
      - qr-menu-network
    restart: unless-stopped

networks:
  qr-menu-network:
    driver: bridge
    name: qr-menu-network

volumes:
  postgres_data:
    name: qr-menu-postgres-data
EOF
```

### 3. Environment Configuration

```bash
# Create environment file
cat > .env << 'EOF'
# Production URLs (replace with your domain)
APP_BASE_URL=https://yourdomain.com
FRONTEND_URL=https://yourdomain.com

# Database Security
DB_PASSWORD=your-secure-database-password-here

# Optional: Custom PostgreSQL configuration
# POSTGRES_HOST=external-db-host.com
# POSTGRES_PORT=5432
# POSTGRES_DB=qrmenudb
# POSTGRES_USER=qrmenu_user
EOF

# Secure the environment file
chmod 600 .env
```

### 4. SSL Configuration (Optional but Recommended)

```bash
# Install Certbot
sudo apt install certbot

# Generate SSL certificate
sudo certbot certonly --standalone -d yourdomain.com

# Create nginx configuration for SSL
cat > nginx-ssl.conf << 'EOF'
events {
    worker_connections 1024;
}

http {
    include /etc/nginx/mime.types;
    default_type application/octet-stream;

    # SSL Configuration
    server {
        listen 80;
        server_name yourdomain.com;
        return 301 https://$server_name$request_uri;
    }

    server {
        listen 443 ssl http2;
        server_name yourdomain.com;

        ssl_certificate /etc/letsencrypt/live/yourdomain.com/fullchain.pem;
        ssl_certificate_key /etc/letsencrypt/live/yourdomain.com/privkey.pem;

        location /api/ {
            proxy_pass http://localhost:8080/api/;
            proxy_http_version 1.1;
            proxy_set_header Upgrade $http_upgrade;
            proxy_set_header Connection 'upgrade';
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto $scheme;
        }

        location / {
            proxy_pass http://localhost/;
            proxy_http_version 1.1;
            proxy_set_header Upgrade $http_upgrade;
            proxy_set_header Connection 'upgrade';
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto $scheme;
        }
    }
}
EOF
```

### 5. Deploy Application

```bash
# Pull latest images
docker-compose pull

# Start services
docker-compose up -d

# Verify deployment
docker-compose ps
docker-compose logs
```

## Post-Deployment Verification

### 1. Health Checks

```bash
# Check container status
docker-compose ps

# Verify frontend accessibility
curl -I http://localhost

# Verify backend API
curl -s http://localhost:8080/api/restaurants

# Check database connectivity
docker-compose exec postgres psql -U qrmenu_user -d qrmenudb -c "SELECT version();"
```

### 2. Test QR Code Generation

```bash
# Create a test restaurant (replace with actual data)
curl -X POST http://localhost:8080/api/restaurants \
  -H "Content-Type: application/json" \
  -d '{
    "name": "Test Restaurant",
    "description": "Test Description",
    "address": "Test Address",
    "phone": "1234567890",
    "email": "test@example.com",
    "themeColor": "#ea580c"
  }'

# Generate QR code (replace {id} with restaurant ID from above)
curl -s http://localhost:8080/api/restaurants/{id}/qr-code
```

## Monitoring and Maintenance

### Log Management

```bash
# View application logs
docker-compose logs -f

# View specific service logs
docker-compose logs -f backend
docker-compose logs -f frontend
docker-compose logs -f postgres

# Log rotation (optional)
sudo tee /etc/logrotate.d/docker-compose << EOF
/var/lib/docker/containers/*/*.log {
    rotate 7
    daily
    compress
    size=1M
    missingok
    delaycompress
    copytruncate
}
EOF
```

### Backup Strategy

```bash
# Create database backup script
cat > backup-database.sh << 'EOF'
#!/bin/bash
BACKUP_DIR="/opt/backups/qr-menu"
DATE=$(date +%Y%m%d_%H%M%S)
mkdir -p $BACKUP_DIR

# Database backup
docker-compose exec -T postgres pg_dump -U qrmenu_user qrmenudb > $BACKUP_DIR/qrmenu_$DATE.sql

# Keep only last 7 days of backups
find $BACKUP_DIR -name "qrmenu_*.sql" -mtime +7 -delete

echo "Backup completed: qrmenu_$DATE.sql"
EOF

chmod +x backup-database.sh

# Add to crontab for daily backups
echo "0 2 * * * /opt/qr-menu-generator/backup-database.sh" | sudo tee -a /etc/crontab
```

### Update Process

```bash
# Create update script
cat > update-application.sh << 'EOF'
#!/bin/bash
echo "Updating QR Menu Generator..."

# Pull latest images
docker-compose pull

# Recreate containers with new images
docker-compose up -d --force-recreate

# Clean up old images
docker image prune -f

echo "Update completed successfully"
EOF

chmod +x update-application.sh
```

## Troubleshooting

### Common Issues

1. **Containers not starting**
   ```bash
   # Check logs
   docker-compose logs
   
   # Verify environment variables
   docker-compose config
   
   # Check port conflicts
   sudo netstat -tulpn | grep :80
   sudo netstat -tulpn | grep :8080
   ```

2. **Database connection issues**
   ```bash
   # Check PostgreSQL container
   docker-compose exec postgres psql -U qrmenu_user -d qrmenudb
   
   # Verify network connectivity
   docker network ls
   docker network inspect qr-menu-network
   ```

3. **CORS errors**
   ```bash
   # Verify environment variables
   docker-compose exec backend env | grep -E "(APP_BASE_URL|FRONTEND_URL)"
   
   # Check CORS configuration in logs
   docker-compose logs backend | grep -i cors
   ```

### Performance Optimization

```bash
# Increase shared memory for PostgreSQL
echo "tmpfs /dev/shm tmpfs defaults,size=512M 0 0" >> /etc/fstab

# Docker daemon configuration
sudo tee /etc/docker/daemon.json << EOF
{
  "log-driver": "json-file",
  "log-opts": {
    "max-size": "10m",
    "max-file": "3"
  },
  "storage-driver": "overlay2"
}
EOF

sudo systemctl restart docker
```

## Security Recommendations

### Container Security

```bash
# Run security scan on images
docker run --rm -v /var/run/docker.sock:/var/run/docker.sock \
  aquasec/trivy image bansikah/qr-menu-backend:latest

# Check for vulnerabilities
docker run --rm -v /var/run/docker.sock:/var/run/docker.sock \
  aquasec/trivy image bansikah/qr-menu-frontend:latest
```

### Database Security

```bash
# Create read-only user for monitoring
docker-compose exec postgres psql -U qrmenu_user -d qrmenudb << EOF
CREATE USER readonly_user WITH PASSWORD 'readonly_password';
GRANT CONNECT ON DATABASE qrmenudb TO readonly_user;
GRANT USAGE ON SCHEMA public TO readonly_user;
GRANT SELECT ON ALL TABLES IN SCHEMA public TO readonly_user;
ALTER DEFAULT PRIVILEGES IN SCHEMA public GRANT SELECT ON TABLES TO readonly_user;
EOF
```

### Firewall Configuration

```bash
# Configure UFW firewall
sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow ssh
sudo ufw allow 80/tcp
sudo ufw allow 443/tcp
sudo ufw enable
```