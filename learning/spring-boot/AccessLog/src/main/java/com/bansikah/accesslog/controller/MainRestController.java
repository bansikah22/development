package com.bansikah.accesslog.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1")
public class MainRestController {

    // Endpoint to test the API, returns an empty JSON object
    @RequestMapping(value = "/test1", produces = "application/json")
    public String test1() {
        return "{}";
    }

    // Endpoint to test the API, returns a 404 Not Found response with JSON content type
    @RequestMapping("/test2")
    public ResponseEntity<?> getTest2() {
        return ResponseEntity.notFound().header("Content-Type", "application/json").build();
    }
}
