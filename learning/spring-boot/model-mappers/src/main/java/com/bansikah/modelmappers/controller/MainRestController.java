package com.bansikah.modelmappers.controller;


import com.bansikah.modelmappers.dto.UserDTO;
import com.bansikah.modelmappers.service.UserService;
import lombok.extern.slf4j.XSlf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@XSlf4j
@RequestMapping("/api/v1")
public class MainRestController {

    @Autowired
    private UserService userService;

    // Endpoint to get user details
    @GetMapping("/user")
    public UserDTO getUser() {
        // Call the service to get user details and return the UserDTO
        return userService.getUser();
    }
}