package com.bansikah.multipleinterfaces.model;

public class UserV1 {
    private Long id;
    private String name;

    public UserV1(Long id, String name) {
        this.id = id;
        this.name = name;
    }

    public Long getId() {
        return id;
    }

    public String getName() {
        return name;
    }
}