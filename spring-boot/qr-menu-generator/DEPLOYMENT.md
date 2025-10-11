# QR Menu Generator - Production Deployment Guide

## 🚀 Quick Start for DevOps

This application is designed for zero-config deployment across different environments. **No manual URL changes required!**

### ✨ Smart URL Configuration
- **QR Code Links**: Automatically generates correct URLs for your domain (e.g., `https://qrmenugenerator.com/api/menu/1`)
- **CORS Configuration**: Automatically handles cross-origin requests for your domain
- **Environment Detection**: Works on localhost, EC2, custom domains without code changes

### Minimum Requirements
- Docker & Docker Compose
- 1GB RAM, 10GB disk space
- Port 80 and 8080 available (configurable)

### One-Command Deployment
```bash
# Clone and deploy in under 2 minutes
git clone <repository-url>
cd qr-menu-generator
./deploy.sh
```

## 📋 Deployment Scenarios

### 1. AWS EC2 Deployment
```bash
# No configuration needed - auto-detects EC2 environment
./deploy.sh --environment production

# Access via EC2 public IP or domain
# Frontend: http://your-ec2-ip
# Backend: http://your-ec2-ip:8080/api
```

### 2. Custom Domain Deployment
```bash
# Create .env file
cat > .env << EOF
APP_DOMAIN=yourdomain.com
FRONTEND_PORT=80
BACKEND_PORT=8080
ENVIRONMENT=production
EOF

# Deploy
./deploy.sh
```

### 3. Behind Load Balancer/Reverse Proxy
```bash
# Create .env file
cat > .env << EOF
APP_DOMAIN=internal.company.com
FRONTEND_PORT=8080
BACKEND_PORT=8081
API_BASE_URL=https://api.company.com
ENVIRONMENT=production
EOF

# Deploy
./deploy.sh
```

### 4. Development/Staging Environment
```bash
./deploy.sh --environment staging
```

## 🔧 Configuration Options

### 🌐 URL Configuration (Critical for QR Codes)

The application automatically generates correct URLs for QR codes and menu links. For production deployment:

#### For Custom Domain (e.g., https://qrmenugenerator.com)
```bash
# Create .env file
APP_BASE_URL=https://qrmenugenerator.com
FRONTEND_URL=https://qrmenugenerator.com
```

#### For EC2 with Public IP (e.g., http://54.123.45.67)
```bash
# Create .env file  
APP_BASE_URL=http://54.123.45.67
FRONTEND_URL=http://54.123.45.67
```

#### Result: QR Codes will contain correct URLs
- ✅ Instead of: `http://localhost:8080/api/menu/1`
- ✅ You get: `https://qrmenugenerator.com/api/menu/1`

### Environment Variables (.env file)
```bash
# URL Configuration (REQUIRED for production)
APP_BASE_URL=https://yourdomain.com     # Base URL for QR codes and API links
FRONTEND_URL=https://yourdomain.com     # Frontend URL for CORS

# Basic Configuration
ENVIRONMENT=production          # deployment environment
FRONTEND_PORT=80               # frontend port
BACKEND_PORT=8080             # backend port

# Advanced Configuration
DB_TYPE=postgresql            # database type (h2/postgresql/mysql)
LOG_LEVEL=INFO               # logging level

# Resource Limits
BACKEND_MEMORY_LIMIT=512m    # backend memory limit
FRONTEND_MEMORY_LIMIT=128m   # frontend memory limit
```

### Database Options

#### H2 (Default - Zero Config)
```bash
# No configuration needed - works out of the box
# Data persisted in Docker volume
```

#### PostgreSQL (Production Recommended)
```bash
# Add to .env
DB_TYPE=postgresql
DB_HOST=localhost
DB_PORT=5432
DB_NAME=qrmenu
DB_USERNAME=qrmenu_user
DB_PASSWORD=secure_password
```

#### MySQL
```bash
# Add to .env
DB_TYPE=mysql
DB_HOST=localhost
DB_PORT=3306
DB_NAME=qrmenu
DB_USERNAME=qrmenu_user
DB_PASSWORD=secure_password
```

## 🌐 Network Architecture

### Smart API URL Detection
The application automatically detects the correct API URL based on the deployment environment:

1. **Development**: Uses localhost:8080
2. **Docker Compose**: Uses container networking
3. **Production**: Uses same domain as frontend with /api path
4. **Custom**: Can be overridden with API_BASE_URL

### Nginx Reverse Proxy
The frontend includes an nginx reverse proxy that:
- Serves the React app
- Proxies `/api/*` requests to the backend
- Handles CORS automatically
- Provides SSL termination ready setup

## 🔒 Security Features

### Container Security
- **Distroless images** - No shell or package managers
- **Non-root users** - Containers run as unprivileged users
- **Minimal attack surface** - Only essential components included
- **Resource limits** - Memory and CPU constraints applied

### Network Security
- **Security headers** - XSS, CSRF, clickjacking protection
- **CORS configuration** - Configurable cross-origin policies
- **SSL ready** - HTTPS configuration templates included

## 📊 Monitoring & Health Checks

### Built-in Endpoints
- **Frontend health**: `http://domain/health`
- **Backend health**: `http://domain/actuator/health`
- **API documentation**: `http://domain/api` (if enabled)

### Logging
```bash
# View application logs
docker-compose logs -f

# View specific service logs
docker-compose logs -f backend
docker-compose logs -f frontend
```

### Metrics
```bash
# Container stats
docker stats

# Service status
docker-compose ps
```

## 🚀 Advanced Deployment Options

### Docker Swarm
```bash
# Convert to swarm stack
docker stack deploy -c docker-compose.yml qrmenu

# Scale services
docker service scale qrmenu_backend=2
docker service scale qrmenu_frontend=3
```

### Kubernetes
```yaml
# Example k8s deployment (create separate yaml files)
apiVersion: apps/v1
kind: Deployment
metadata:
  name: qrmenu-backend
spec:
  replicas: 2
  selector:
    matchLabels:
      app: qrmenu-backend
  template:
    metadata:
      labels:
        app: qrmenu-backend
    spec:
      containers:
      - name: backend
        image: qrmenu-backend:latest
        ports:
        - containerPort: 8080
        env:
        - name: SPRING_PROFILES_ACTIVE
          value: "kubernetes"
```

### CI/CD Pipeline Example (GitHub Actions)
```yaml
name: Deploy QR Menu Generator
on:
  push:
    branches: [main]

jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    
    - name: Deploy to production
      run: |
        ./deploy.sh --environment production --skip-tests
```

## 🔧 Troubleshooting

### Common Issues

#### Port Already in Use
```bash
# Check what's using the port
sudo lsof -i :80
sudo lsof -i :8080

# Use different ports
echo "FRONTEND_PORT=8080" >> .env
echo "BACKEND_PORT=8081" >> .env
```

#### Permission Issues
```bash
# Fix file permissions
chmod +x deploy.sh
sudo chown -R $USER:$USER .
```

#### Memory Issues
```bash
# Reduce memory limits
echo "BACKEND_MEMORY_LIMIT=256m" >> .env
echo "FRONTEND_MEMORY_LIMIT=64m" >> .env
```

### Service Recovery
```bash
# Restart all services
docker-compose restart

# Rebuild and restart
docker-compose up --build -d

# Reset everything
docker-compose down -v
docker-compose up --build -d
```

### Database Recovery
```bash
# Backup database (H2)
docker-compose exec backend cp /app/data/qrmenugendb.mv.db /app/data/backup.mv.db

# Restore database (H2)
docker-compose exec backend cp /app/data/backup.mv.db /app/data/qrmenugendb.mv.db
docker-compose restart backend
```

## 📞 Support & Maintenance

### Log Locations
- Application logs: `docker-compose logs`
- Database data: Docker volume `qr-menu-backend-data`
- Configuration: `.env` file

### Backup Strategy
```bash
# Backup script example
#!/bin/bash
DATE=$(date +%Y%m%d_%H%M%S)
docker-compose exec backend cp /app/data/qrmenugendb.mv.db /app/data/backup_$DATE.mv.db
echo "Backup created: backup_$DATE.mv.db"
```

### Update Process
```bash
# Pull latest code
git pull origin main

# Rebuild and deploy
./deploy.sh --environment production
```

This deployment guide ensures your DevOps team can deploy the application anywhere without requiring application-specific knowledge or manual configuration changes.