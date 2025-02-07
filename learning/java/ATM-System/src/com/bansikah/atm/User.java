package com.bansikah.atm;

public class User {
    private String name;
    private Account account; // account instance

    public User(String name, Account account) {
        this.name = name;
        this.account = account;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    //getAccount method
    public Account getAccount() {
        return this.account;
    }

    public void setAccount(Account account) {
        this.account = account;
    }

    @Override
    public String toString() {
        return "User{name='" + name + "', account=" + account + "}";
    }
}
