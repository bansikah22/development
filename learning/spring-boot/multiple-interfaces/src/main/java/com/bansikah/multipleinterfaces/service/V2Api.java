package com.bansikah.multipleinterfaces.service;

import com.bansikah.multipleinterfaces.model.UserV2;

import java.util.List;

public interface V2Api extends V1Api {
    UserV2 getUserDetails(Long id);

    // Add a new method to the V2Api interface
    List<UserV2> getAllUserDetails();
}