# Model Mappers in Java

## What are Model Mappers?

Model mappers are tools or libraries used to map data between different object models, typically between Data Transfer Objects (DTOs) and entity models. This is particularly useful in applications where data needs to be transferred between different layers, such as from the database layer to the service layer and then to the presentation layer.

## Why are Model Mappers Important?

1. **Separation of Concerns**: They help in maintaining a clear separation between different layers of an application.
2. **Code Reusability**: They promote code reusability by allowing the same mapping logic to be used across different parts of the application.
3. **Simplified Code**: They reduce boilerplate code by automating the mapping process.
4. **Consistency**: They ensure consistent data transformation across the application.

## Implementation in the Code

In this project, the `ModelMapper` library is used to map between `User` entity and `UserDTO`. Below is a brief explanation of how it has been implemented:

### 1. Configuration

A `ModelMapper` bean is defined in the `MapperConfig` class to be used throughout the application.

```java
package com.bansikah.modelmappers.utils;

import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

@Component
public class MapperConfig {

    @Bean
    public ModelMapper modelMapper() {
        return new ModelMapper();
    }
}
```
2. Entity and DTO Classes
The `User` entity and `UserDTO` classes are defined to represent the user data in different layers.
```java
package com.bansikah.modelmappers.model;

import lombok.Data;

@Data
public class User {
    private String id;
    private String firstName;
    private String lastName;
    private String email;
    private String password;
}
```
```java
package com.bansikah.modelmappers.dto;

import lombok.Data;

@Data
public class UserDTO {
    private String id;
    private String firstName;
    private String lastName;
    private String fullName;
    private String email;
}
```

3. Service Layer
The UserService class uses the UserDTOConverter to convert User entities to UserDTO objects.
```java
package com.bansikah.modelmappers.service;

import com.bansikah.modelmappers.converter.UserDTOConverter;
import com.bansikah.modelmappers.dto.UserDTO;
import com.bansikah.modelmappers.model.User;
import lombok.extern.slf4j.XSlf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
@XSlf4j
public class UserService {

    @Autowired
    private UserDTOConverter userDTOConverter;

    public UserDTO getUser() {
        User user = new User();
        user.setId("1");
        user.setFirstName("John");
        user.setLastName("Doe");
        user.setEmail("john@me.com");
        user.setPassword("password");

        UserDTO userDTO = userDTOConverter.convertuserToUserDTO(user);
        return userDTO;
    }
}
```

By using ModelMapper, the project ensures that the mapping between User and UserDTO is handled efficiently and consistently, reducing the need for manual mapping code and potential errors.

