package com.bansikah.multipleinterfaces.controller;

import com.bansikah.multipleinterfaces.model.UserV1;
import com.bansikah.multipleinterfaces.service.V1Api;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/v1/users")
public class UserV1Controller {
    private final V1Api userService;

    public UserV1Controller(V1Api userService) {
        this.userService = userService;
    }

    @GetMapping
    public List<UserV1> getAllUsers() {
        return userService.getAllUsers();
    }

    @GetMapping("/{id}")
    public UserV1 getUserById(@PathVariable Long id) {
        return userService.getUserById(id);
    }
}
