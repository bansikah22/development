package com.bansikah.mapstructdemo.service;

import com.bansikah.mapstructdemo.dto.UserDTO;
import com.bansikah.mapstructdemo.mapper.UserMapper;
import com.bansikah.mapstructdemo.model.User;
import com.bansikah.mapstructdemo.repository.UserRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserService {

    private final UserRepository userRepository;
    private final UserMapper userMapper;

    public UserService(UserRepository userRepository, UserMapper userMapper) {
        this.userRepository = userRepository;
        this.userMapper = userMapper;
    }

    public UserDTO createUser(UserDTO userDTO) {
        // Convert DTO to entity
        User user = userMapper.toEntity(userDTO);
        // Save to DB
        User saved = userRepository.save(user);
        // Convert back to DTO
        return userMapper.toDto(saved);
    }

    public List<UserDTO> getAllUsers() {
        List<User> users = userRepository.findAll();
        return userMapper.toDtoList(users);
    }
}
