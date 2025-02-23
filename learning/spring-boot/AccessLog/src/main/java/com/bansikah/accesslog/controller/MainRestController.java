package com.bansikah.accesslog.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1")
public class MainRestController {

    @RequestMapping(value = "/test1", produces = "application/json")
    public String test1() {
        return "{}";
    }

    @RequestMapping("/test2")
    public ResponseEntity<?> getTest2() {
        return ResponseEntity.notFound().header("Content-Type", "application/json").build();
    }
}
