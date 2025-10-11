# QR Menu Generator

A modern, production-ready QR Code Menu Generator built with Spring Boot and React. Allows restaurants to create digital menus accessible via QR codes with automatic URL configuration for seamless deployment.

## Features

- **Smart QR Code Generation**: QR codes automatically use correct production URLs
- **Restaurant Management**: Complete restaurant information management  
- **Menu Management**: Add, edit, and organize menu items with categories
- **Modern UI**: Clean, responsive design with glassmorphism and 2025 design trends
- **Customer Menu View**: Beautiful, branded customer-facing menu display
- **Production-Ready**: Optimized Docker images with PostgreSQL database
- **Environment Aware**: Automatic CORS and URL configuration for deployment
- **Security Focused**: Non-root containers, security headers, input validation

## Architecture

### Backend (Spring Boot 3.1.0 + Java 17)
- **PostgreSQL Database** for production reliability
- **MapStruct** for clean DTO mapping
- **ZXing** for QR code generation
- **Global CORS Configuration** for environment-aware security
- **Environment-based URL Configuration** for deployment flexibility

### Frontend (React 18 + TypeScript)
- **Vite** for fast development and optimized builds
- **Tailwind CSS v3.4.0** for modern styling
- **Smart API Detection** for environment-aware configuration
- **Nginx Reverse Proxy** for production serving

### Infrastructure
- **Multi-stage Docker Builds** for minimal image sizes
- **PostgreSQL 15** with persistent volumes
- **Security Headers** and non-root containers
- **Docker Registry**: Available on Docker Hub as `bansikah/qr-menu-backend` and `bansikah/qr-menu-frontend`

## Quick Start

### Prerequisites
- Docker & Docker Compose

### Run with Docker Compose (Production Images)
```bash
# Download docker-compose file
curl -O https://raw.githubusercontent.com/your-repo/qr-menu-generator/main/docker-compose.prod.yml

# Set environment variables
export APP_BASE_URL=https://yourdomain.com
export FRONTEND_URL=https://yourdomain.com
export DB_PASSWORD=your-secure-password

# Deploy
docker-compose -f docker-compose.prod.yml up -d
# Backend API: http://localhost:8080
# H2 Console: http://localhost:8080/h2-console
```

### Development Mode
```bash
# Backend (Terminal 1)
cd backend
./mvnw spring-boot:run

# Frontend (Terminal 2)  
cd frontend
npm install
npm run dev
```

## 📁 Project Structure
```
qr-menu-generator/
├── backend/                 # Spring Boot application
│   ├── src/main/java/      # Java source code
│   ├── src/main/resources/ # Configuration files
│   ├── Dockerfile          # Optimized backend Docker image
│   └── pom.xml            # Maven dependencies
├── frontend/               # React application
│   ├── src/               # TypeScript source code
│   ├── public/            # Static assets
│   ├── Dockerfile         # Optimized frontend Docker image
│   ├── nginx.conf         # Production nginx config
│   └── package.json       # Node.js dependencies
└── docker-compose.yml     # Container orchestration
```

## 🔧 Configuration

### Environment Variables
- `VITE_API_BASE_URL`: Backend API URL for frontend
- `SPRING_PROFILES_ACTIVE`: Spring Boot profile (docker/dev)

### Database
- H2 file-based database with persistence
- Data stored in Docker volume: `qr-menu-backend-data`
- Console available at `/h2-console` (dev mode)

## 🛡️ Security Features

### Container Security
- Non-root user execution
- Distroless runtime (no shell, package managers)
- Minimal attack surface
- Security headers in nginx

### Application Security
- Input validation
- CORS configuration
- Secure headers

## 📈 Performance Optimizations

### Backend
- JVM container-aware settings
- String deduplication
- Optimized garbage collection
- JAR layer extraction for caching

### Frontend
- Asset compression (gzip)
- Long-term caching for static assets
- Optimized build configuration
- CDN-ready setup

## 🚀 Deployment

### Production Deployment
The application is ready for production deployment with:
- Optimized Docker images
- Health checks
- Persistent data storage
- Production nginx configuration

### Scaling
- Stateless design allows horizontal scaling
- Database can be externalized (PostgreSQL, MySQL)
- Frontend can be served from CDN

## 🔍 Monitoring

### Health Checks
- Backend: `/actuator/health`
- Frontend: `/health`
- Docker Compose health monitoring

### Logging
- Structured logging in JSON format
- Docker logs aggregation ready
- Configurable log levels

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## 📄 License

This project is licensed under the MIT License.

## 🎯 MVP Completed Features

- ✅ Restaurant management (CRUD)
- ✅ Menu item management (CRUD)
- ✅ QR code generation
- ✅ Customer menu view
- ✅ Modern responsive UI
- ✅ Docker containerization
- ✅ Production optimization

## 🚧 Future Enhancements

- [ ] Image upload for menu items
- [ ] Multiple restaurant support
- [ ] User authentication
- [ ] Analytics dashboard
- [ ] Multi-language support
- [ ] Theme customization
- [ ] Payment integration