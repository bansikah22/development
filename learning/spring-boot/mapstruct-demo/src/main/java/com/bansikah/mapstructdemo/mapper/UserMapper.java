package com.bansikah.mapstructdemo.mapper;

import com.bansikah.mapstructdemo.dto.UserDTO;
import com.bansikah.mapstructdemo.model.User;
import org.mapstruct.Mapper;

import java.util.List;

@Mapper(componentModel = "spring")
public interface UserMapper {
    UserDTO toDto(User user);   // Map Entity → DTO

    User toEntity(UserDTO userDTO);  // Map DTO → Entity


    List<UserDTO> toDtoList(List<User> users);
}
