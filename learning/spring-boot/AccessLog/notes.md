# Access Log Filter in Spring Boot

## Overview

An **Access Log Filter** in Spring Boot is a custom filter that intercepts HTTP requests and logs details about them. This is useful for monitoring and debugging purposes, as it provides insights into the requests being made to the application.

## Implementation Details

### AccessLogFilter

The `AccessLogFilter` class is a custom filter that extends `OncePerRequestFilter`. It logs the details of incoming HTTP requests that start with `/api`. The filter captures the request method, URI, client's IP address, and the timestamp when the request was received.

#### Key Features:
- **Request Logging**: Logs the HTTP method, request URI, client's IP address, and the timestamp.
- **Client IP Extraction**: Extracts the client's IP address considering various headers like `X-Forwarded-For`, `Proxy-Client-IP`, and `WL-Proxy-Client-IP`.

### MainRestController

The `MainRestController` class provides two endpoints for testing purposes:
- **/test1**: Returns an empty JSON object.
- **/test2**: Returns a 404 Not Found response with JSON content type.

### HTTP Requests

The `generated-requests.http` file contains various HTTP requests for testing the API endpoints. These include GET, PUT, POST, and DELETE requests to different endpoints of the application.

## Code Structure

- **src/main/java/com/bansikah/accesslog/filter/AccessLogFilter.java**: Contains the implementation of the `AccessLogFilter` class.
- **src/main/java/com/bansikah/accesslog/controller/MainRestController.java**: Contains the implementation of the `MainRestController` class.
- **generated-requests.http**: Contains sample HTTP requests for testing the API.

## Usage

To use the access log filter, simply run the Spring Boot application. The filter will automatically log the details of incoming HTTP requests that start with `/api`.

## Example Log Output
```bash
Request: GET /api/books from IP: 192.168.1.1 at 1633354800000
```
This log entry indicates that a GET request was made to `/api/books` from the IP address `192.168.1.1` at the specified timestamp.

## Conclusion

The Access Log Filter provides a simple yet effective way to log and monitor HTTP requests in a Spring Boot application. It helps in tracking the requests and understanding the usage patterns of the API.
