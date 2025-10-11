# Build stage - Use specific Maven version for reproducible builds
FROM maven:3.9.5-eclipse-temurin-17-alpine AS builder

# Set working directory
WORKDIR /app

# Copy pom.xml first for better layer caching
COPY pom.xml .

# Download dependencies (cached layer if pom.xml doesn't change)
RUN mvn dependency:go-offline -B

# Copy source code
COPY src ./src

# Build the application with optimizations
RUN mvn clean package -DskipTests -B

# Extract JAR layers for better Docker layer caching
RUN java -Djarmode=layertools -jar target/*.jar extract --destination target/extracted

# Runtime stage - Use lightweight JRE
FROM eclipse-temurin:17-jre-alpine

# Create app user for security
RUN addgroup -g 1001 -S appgroup && \
    adduser -u 1001 -S appuser -G appgroup

# Set working directory  
WORKDIR /app

# Create data directory with proper permissions
RUN mkdir -p /app/data && chown -R appuser:appgroup /app

# Copy the JAR file from builder stage
COPY --from=builder --chown=appuser:appgroup /app/target/*.jar app.jar

# Switch to non-root user
USER appuser

# Expose port
EXPOSE 8080

# Run the application with container-optimized JVM settings
ENTRYPOINT ["java", \
    "-XX:+UseContainerSupport", \
    "-XX:MaxRAMPercentage=75.0", \
    "-Djava.security.egd=file:/dev/./urandom", \
    "-jar", "app.jar"]