package com.bansikah.modelmappers.dto;


import lombok.Data;

@Data
/// Data Transfer Object for User entity.
public class UserDTO {
    private String id;
    private String firstName;
    private String lastName;
    private String fullName;
    private String email;
}
