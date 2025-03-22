package com.bansikah.demolambdaspringboot.service;

import com.bansikah.demolambdaspringboot.model.User;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

@Service
public class UserService {
    private final List<User> users = new ArrayList<>();

    public UserService() {
        users.add(new User(1L, "Banikah", "Banikah@gmail.com"));
        users.add(new User(2L, "Noel", "Noel@gmail.com"));
        users.add(new User(3L, "Draxler", "Draxler@gmail.com"));
    }

    public List<User> getAllUsers() {
        return users;
    }

    public User getUserById(Long id) {
        return users.stream()
                .filter(user -> Objects.equals(user.getId(), id))
                .findFirst()
                .orElse(null);
    }

    public User addUser(User user) {
        users.add(user);
        return user;
    }

    public List<User> getUsersByName(String name) {
        return users.stream()
                .filter(user -> user.getName().equals(name))
                .collect(Collectors.toList());
    }

    public void updateUser(User user) {
        users.stream()
                .filter(u -> Objects.equals(u.getId(), user.getId()))
                .findFirst()
                .ifPresent(existingUser -> {
                    existingUser.setName(user.getName());
                    existingUser.setEmail(user.getEmail());
                });
    }

    public User deleteUser(Long id) {
        User user = getUserById(id);
        users.remove(user);
        return user;
    }
}