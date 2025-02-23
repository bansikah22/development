package com.bansikah.modelmappers.service;


import com.bansikah.modelmappers.converter.UserDTOConverter;
import com.bansikah.modelmappers.dto.UserDTO;
import com.bansikah.modelmappers.model.User;
import lombok.extern.slf4j.XSlf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
@XSlf4j
public class UserService {

    @Autowired
    private UserDTOConverter userDTOConverter;

    // Placeholder for UserDTO object
    public UserDTO userDTO;

    // Method to get a UserDTO object
    public UserDTO getUser() {

        // Mock database call to create a User object
        User user = new User();
        user.setId("1");
        user.setFirstName("John");
        user.setLastName("Doe");
        user.setEmail("john@me.com");
        user.setPassword("password");

        // Convert User entity to UserDTO
        UserDTO userDTO = userDTOConverter.convertuserToUserDTO(user);

        // Return the UserDTO object
        return userDTO;
    }
}
