package com.bansikah.demolambdaspringboot.model;

public class User {
    private Long id;
    private String name;
    private String email;

    //constructors
    public User(Long id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    //getter & setters
    public Long getId() {
        return id;
    }
    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }

    //to string

    @Override
    public String toString() {
        return super.toString();
    }
}
