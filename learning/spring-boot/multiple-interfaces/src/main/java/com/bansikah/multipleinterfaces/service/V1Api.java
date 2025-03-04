package com.bansikah.multipleinterfaces.service;

import com.bansikah.multipleinterfaces.model.UserV1;

import java.util.List;

public interface V1Api {
    List<UserV1> getAllUsers();
    UserV1 getUserById(Long id);
}