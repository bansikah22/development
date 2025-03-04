package com.bansikah.multipleinterfaces.controller;

import com.bansikah.multipleinterfaces.model.UserV2;
import com.bansikah.multipleinterfaces.service.V2Api;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/v2/users")
public class UserV2Controller {
    private final V2Api userService;

    public UserV2Controller(V2Api userService) {
        this.userService = userService;
    }

    @GetMapping("/{id}")
    public UserV2 getUserDetails(@PathVariable Long id) {
        return userService.getUserDetails(id);
    }

    @GetMapping("/all")
    public List<UserV2> getAllUserDetails() {
        return userService.getAllUserDetails();
    }

}
