package com.bansikah.multipleinterfaces.service;

import com.bansikah.multipleinterfaces.model.UserV1;
import com.bansikah.multipleinterfaces.model.UserV2;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;

@Service
public class UserService implements V2Api {

    private final List<UserV1> users = Arrays.asList(
            new UserV1(1L, "Alice"),
            new UserV1(2L, "Bob")
    );

    private final List<UserV2> userDetails = Arrays.asList(
            new UserV2(1L, "Alice", "noel@gmail.com"),
            new UserV2(2L, "Bob", "bansikah@gmail.com")
    );

    @Override
    public List<UserV1> getAllUsers() {
        return users;
    }

    @Override
    public UserV1 getUserById(Long id) {
        return users.stream()
                .filter(user -> user.getId().equals(id))
                .findFirst()
                .orElse(null);
    }

    @Override
    public UserV2 getUserDetails(Long id) {
        return userDetails.stream()
                .filter(user -> user.getId().equals(id))
                .findFirst()
                .orElse(null);
    }


    @Override
    public List<UserV2> getAllUserDetails() {
        return userDetails;
    }
}
