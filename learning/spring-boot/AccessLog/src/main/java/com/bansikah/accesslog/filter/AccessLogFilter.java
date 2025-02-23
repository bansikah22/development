package com.bansikah.accesslog.filter;

import jakarta.servlet.FilterChain;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;
import org.springframework.web.filter.OncePerRequestFilter;
import lombok.extern.slf4j.Slf4j;

import java.io.IOException;

@Component
@Slf4j
@Order(Ordered.HIGHEST_PRECEDENCE)
public class AccessLogFilter extends OncePerRequestFilter {

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain)
            throws ServletException, IOException {

        // Check if the request URI starts with "/api"
        if (request.getRequestURI().startsWith("/api")) {
            // Record the start time of the request
            long startTime = System.currentTimeMillis();
            // Get the client's IP address
            String ipAddress = getClientIpAddress(request);

            // Log the request details
            log.info("Request: {} {} from IP: {} at {}",
                    request.getMethod(), request.getRequestURI(), ipAddress, startTime);
        }

        // Continue the filter chain
        filterChain.doFilter(request, response);
    }

    /**
     * Extracts the client IP address, considering proxies.
     *
     * @param request the HttpServletRequest object
     * @return the client IP address as a String
     */
    private String getClientIpAddress(HttpServletRequest request) {
        // Check the "X-Forwarded-For" header first
        String ip = request.getHeader("X-Forwarded-For");
        if (ip == null || ip.isEmpty() || "unknown".equalsIgnoreCase(ip)) {
            // Check the "Proxy-Client-IP" header
            ip = request.getHeader("Proxy-Client-IP");
        }
        if (ip == null || ip.isEmpty() || "unknown".equalsIgnoreCase(ip)) {
            // Check the "WL-Proxy-Client-IP" header
            ip = request.getHeader("WL-Proxy-Client-IP");
        }
        if (ip == null || ip.isEmpty() || "unknown".equalsIgnoreCase(ip)) {
            // Fallback to the remote address
            ip = request.getRemoteAddr();
        }
        return ip;
    }
}