# QR Menu Generator Documentation

## Table of Contents

1. [Project Overview](#project-overview)
2. [Architecture](#architecture)
3. [Technology Stack](#technology-stack)
4. [Development Setup](#development-setup)
5. [Production Deployment](#production-deployment)
6. [API Documentation](#api-documentation)
7. [Docker Configuration](#docker-configuration)
8. [Environment Configuration](#environment-configuration)

## Project Overview

The QR Menu Generator is a full-stack application that allows restaurants to create digital menus accessible via QR codes. Restaurant owners can manage their restaurant information and menu items through a web interface, generate QR codes that customers can scan to view menus instantly.

### Key Features

- Restaurant management (name, description, contact info, branding)
- Menu item management with categories, pricing, and availability
- QR code generation with customizable base URLs for deployment flexibility
- Modern responsive UI with glassmorphism design elements
- Production-ready Docker containerization
- PostgreSQL database for data persistence
- Environment-aware configuration for seamless deployment

## Architecture

The application follows a microservices architecture with clear separation of concerns:

### Frontend (React + TypeScript)
- Modern React 18+ application with TypeScript
- Vite build tool for fast development and optimized production builds
- Tailwind CSS for styling with custom design system
- Smart API URL detection based on deployment environment
- Nginx reverse proxy for production serving

### Backend (Spring Boot)
- Spring Boot 3.1.0 with Java 17
- RESTful API design with proper HTTP status codes
- JPA/Hibernate for database operations
- MapStruct for clean DTO mapping
- ZXing library for QR code generation
- Global CORS configuration for cross-origin requests

### Database (PostgreSQL)
- PostgreSQL 15 for production reliability
- Automatic schema generation via JPA
- Persistent volumes for data retention
- Optimized connection pooling

### Infrastructure
- Docker containers for all services
- Multi-stage builds for minimal image sizes
- Docker Compose orchestration
- Environment variable configuration
- Production-ready security headers

## Technology Stack

### Backend Technologies
- **Java 17**: Modern LTS Java version
- **Spring Boot 3.1.0**: Framework for rapid development
- **Spring Data JPA**: Database abstraction layer
- **PostgreSQL Driver**: Database connectivity
- **MapStruct 1.5.5**: Type-safe bean mapping
- **ZXing 3.5.1**: QR code generation library
- **Maven**: Build and dependency management

### Frontend Technologies
- **React 18+**: Modern React with hooks and concurrent features
- **TypeScript**: Type safety and better development experience
- **Vite**: Fast build tool and development server
- **Tailwind CSS 3.4.0**: Utility-first CSS framework
- **React Hook Form**: Form validation and management
- **Axios**: HTTP client for API communication

### Infrastructure Technologies
- **Docker**: Containerization platform
- **Docker Compose**: Multi-container orchestration
- **Nginx**: Reverse proxy and static file serving
- **PostgreSQL 15**: Production database
- **Alpine Linux**: Lightweight base images

## Development Setup

### Prerequisites
- Docker and Docker Compose
- Git for version control
- Node.js 18+ (for local frontend development)
- Java 17+ and Maven (for local backend development)

### Local Development with Docker

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd qr-menu-generator
   ```

2. **Start all services**
   ```bash
   docker-compose up --build
   ```

3. **Access the application**
   - Frontend: http://localhost
   - Backend API: http://localhost:8080/api
   - Database: localhost:5432

### Local Development without Docker

1. **Backend Setup**
   ```bash
   cd backend
   mvn spring-boot:run
   ```

2. **Frontend Setup**
   ```bash
   cd frontend
   npm install
   npm run dev
   ```

## Production Deployment

### Docker Registry Images

The application images are available on Docker Hub:
- **Backend**: `bansikah/qr-menu-backend:latest`
- **Frontend**: `bansikah/qr-menu-frontend:latest`

### Production Docker Compose

Create a production `docker-compose.prod.yml`:

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

  backend:
    image: bansikah/qr-menu-backend:latest
    environment:
      - SPRING_PROFILES_ACTIVE=docker
      - APP_BASE_URL=${APP_BASE_URL}
      - FRONTEND_URL=${FRONTEND_URL}
      - SPRING_DATASOURCE_PASSWORD=${DB_PASSWORD}
    depends_on:
      - postgres
    restart: unless-stopped

  frontend:
    image: bansikah/qr-menu-frontend:latest
    ports:
      - "80:8080"
    depends_on:
      - backend
    restart: unless-stopped

volumes:
  postgres_data:
```

### Environment Configuration

Create a `.env` file for production:

```bash
# Production URLs
APP_BASE_URL=https://yourdomain.com
FRONTEND_URL=https://yourdomain.com

# Database Security
DB_PASSWORD=your-secure-database-password
```

### Deployment Steps

1. **Prepare server**
   ```bash
   # Install Docker and Docker Compose
   # Configure firewall (ports 80, 443)
   # Set up SSL certificates if using HTTPS
   ```

2. **Deploy application**
   ```bash
   # Copy docker-compose.prod.yml and .env to server
   docker-compose -f docker-compose.prod.yml up -d
   ```

3. **Verify deployment**
   ```bash
   # Check container status
   docker-compose ps
   
   # View logs
   docker-compose logs
   ```

## API Documentation

### Base URL Structure
- Development: `http://localhost:8080/api`
- Production: `https://yourdomain.com/api`

### Restaurant Endpoints

#### Create Restaurant
```http
POST /api/restaurants
Content-Type: application/json

{
  "name": "Restaurant Name",
  "description": "Restaurant Description",
  "address": "Full Address",
  "phone": "Phone Number",
  "email": "email@example.com",
  "themeColor": "#ea580c"
}
```

#### Get All Restaurants
```http
GET /api/restaurants
```

#### Get Restaurant by ID
```http
GET /api/restaurants/{id}
```

#### Update Restaurant
```http
PUT /api/restaurants/{id}
Content-Type: application/json
```

#### Delete Restaurant
```http
DELETE /api/restaurants/{id}
```

### Menu Item Endpoints

#### Add Menu Item
```http
POST /api/restaurants/{restaurantId}/menu-items
Content-Type: application/json

{
  "name": "Menu Item Name",
  "description": "Item Description",
  "price": 15.99,
  "category": "Main Course",
  "imageUrl": "https://example.com/image.jpg",
  "available": true
}
```

#### Get Menu Items
```http
GET /api/restaurants/{restaurantId}/menu-items
```

#### Update Menu Item
```http
PUT /api/menu-items/{itemId}
```

#### Delete Menu Item
```http
DELETE /api/menu-items/{itemId}
```

### QR Code Endpoints

#### Generate QR Code
```http
GET /api/restaurants/{id}/qr-code

Response:
{
  "qrCode": "data:image/png;base64,iVBORw0KGgo...",
  "menuUrl": "https://yourdomain.com/api/menu/1"
}
```

### Customer Menu Endpoint

#### Get Public Menu
```http
GET /api/menu/{restaurantId}

Response: Complete restaurant and menu data for customer viewing
```

## Docker Configuration

### Multi-stage Builds

Both frontend and backend use optimized multi-stage builds:

#### Backend Dockerfile Strategy
1. **Builder stage**: Maven with full JDK for compilation
2. **Runtime stage**: Minimal JRE with only the JAR file
3. **Security**: Non-root user with proper permissions
4. **Optimization**: Layer extraction for better caching

#### Frontend Dockerfile Strategy  
1. **Builder stage**: Node.js for building React application
2. **Runtime stage**: Nginx Alpine for serving static files
3. **Configuration**: Custom nginx.conf for SPA routing
4. **Security**: Production-ready security headers

### Container Networking

All services communicate through a custom Docker network:
- **Frontend Container**: Serves UI on port 8080 (mapped to host port 80)
- **Backend Container**: API server on port 8080 (internal)
- **Database Container**: PostgreSQL on port 5432 (internal)

### Volume Management

Persistent storage for database:
```yaml
volumes:
  postgres_data:
    name: qr-menu-postgres-data
```

## Environment Configuration

### Development Environment Variables

```yaml
# Backend Configuration
SPRING_PROFILES_ACTIVE=docker
APP_BASE_URL=http://localhost
FRONTEND_URL=http://localhost

# Database Configuration  
SPRING_DATASOURCE_URL=jdbc:postgresql://postgres:5432/qrmenudb
SPRING_DATASOURCE_USERNAME=qrmenu_user
SPRING_DATASOURCE_PASSWORD=qrmenu_password
```

### Production Environment Variables

```bash
# Application URLs
APP_BASE_URL=https://yourdomain.com
FRONTEND_URL=https://yourdomain.com

# Database Security
DB_PASSWORD=secure-production-password

# Optional: Custom database host
POSTGRES_HOST=external-db-host.com
```

### CORS Configuration

The application automatically configures CORS based on the `FRONTEND_URL` environment variable:

```java
@Configuration
public class CorsConfig implements WebMvcConfigurer {
    @Override
    public void addCorsMappings(CorsRegistry registry) {
        registry.addMapping("/api/**")
                .allowedOriginPatterns(allowedOrigins.toArray(new String[0]))
                .allowedMethods("GET", "POST", "PUT", "DELETE", "OPTIONS")
                .allowedHeaders("*")
                .allowCredentials(true)
                .maxAge(3600);
    }
}
```

### URL Generation Logic

QR codes automatically generate correct URLs based on environment:

```java
@Service
public class QrCodeService {
    @Value("${app.base-url:http://localhost:8080}")
    private String baseUrl;
    
    public String generateQrCode(Long restaurantId) {
        String menuUrl = baseUrl + "/api/menu/" + restaurantId;
        // QR code generation logic
    }
}
```

This ensures QR codes contain the correct production URLs without code changes.