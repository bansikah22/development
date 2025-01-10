package com.bansikah.bankingapp.repository;


import com.bansikah.bankingapp.model.Account;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AccountRepository extends JpaRepository<Account, Long> {
}
