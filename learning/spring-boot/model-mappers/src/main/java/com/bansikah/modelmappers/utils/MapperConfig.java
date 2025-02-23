package com.bansikah.modelmappers.utils;


import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

@Component
public class MapperConfig {

    // Define a bean for ModelMapper to be used for object mapping
    @Bean
    public ModelMapper modelMapper() {
        return new ModelMapper();
    }
}

