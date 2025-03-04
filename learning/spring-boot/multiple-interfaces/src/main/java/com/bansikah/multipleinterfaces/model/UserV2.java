package com.bansikah.multipleinterfaces.model;

public class UserV2 extends UserV1 {
    private String email;

    public UserV2(Long id, String name, String email) {
        super(id, name);
        this.email = email;
    }

    public String getEmail() {
        return email;
    }
}