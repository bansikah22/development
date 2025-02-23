package com.bansikah.modelmappers.model;

import lombok.Data;

// Entity class representing a User in the system
@Data
public class User {
    private String id;
    private String firstName;
    private String lastName;
    private String email;
    private String password;
}
