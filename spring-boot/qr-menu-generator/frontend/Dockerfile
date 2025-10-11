# Build stage - Use specific Node version for reproducibility
FROM node:18.19-alpine3.19 AS builder

# Build arguments for environment configuration
ARG VITE_API_BASE_URL
ARG VITE_ENVIRONMENT=production

# Install build dependencies for potential native modules
RUN apk add --no-cache python3 make g++

# Set working directory
WORKDIR /app

# Copy package files for better layer caching
COPY package*.json ./

# Install dependencies with production optimizations
RUN npm ci --only=production --no-audit --no-fund && npm cache clean --force

# Install dev dependencies for build
RUN npm ci --include=dev --no-audit --no-fund

# Copy source code
COPY . .

# Set environment variables for build
ENV VITE_API_BASE_URL=${VITE_API_BASE_URL}
ENV VITE_ENVIRONMENT=${VITE_ENVIRONMENT}

# Build the application with production optimizations
RUN npm run build

# Production stage - Use standard nginx
FROM nginx:alpine

# Copy built application from builder stage
COPY --from=builder /app/dist /usr/share/nginx/html

# Copy nginx configuration
COPY nginx.conf /etc/nginx/nginx.conf

# Expose port 8080
EXPOSE 8080

# Start nginx
CMD ["nginx", "-g", "daemon off;"]