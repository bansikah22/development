package com.bansikah.mapstructdemo.repository;

import com.bansikah.mapstructdemo.model.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User, Long> {
}
