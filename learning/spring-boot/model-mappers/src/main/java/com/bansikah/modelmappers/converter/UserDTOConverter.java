package com.bansikah.modelmappers.converter;


import org.modelmapper.ModelMapper;
import com.bansikah.modelmappers.dto.UserDTO;
import com.bansikah.modelmappers.model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class UserDTOConverter {

    @Autowired
    private ModelMapper modelMapper;

    // Convert User entity to UserDTO
    public UserDTO convertuserToUserDTO(User user) {
        // Map User entity to UserDTO
        UserDTO userDTO = modelMapper.map(user, UserDTO.class);

        // Set full name in UserDTO
        userDTO.setFullName(user.getFirstName() + " " + user.getLastName());

        return userDTO;
    }

    // Convert UserDTO to User entity
    public User convertUserDTOToUser(UserDTO userDTO) {
        // Map UserDTO to User entity
        return modelMapper.map(userDTO, User.class);
    }

}
