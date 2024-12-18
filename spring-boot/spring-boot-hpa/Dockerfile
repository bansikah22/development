FROM openjdk:17-jdk-slim

# Argument for the JAR file to copy
ARG JAR_FILE=target/spring-boot-hpa-0.0.1-SNAPSHOT.jar

# Copy the JAR file into the container
COPY ${JAR_FILE} app.jar

EXPOSE 8082

ENTRYPOINT ["java", "-jar", "/app.jar"]

