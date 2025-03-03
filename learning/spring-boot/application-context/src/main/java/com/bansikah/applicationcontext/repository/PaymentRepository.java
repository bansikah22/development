package com.bansikah.applicationcontext.repository;

import com.bansikah.applicationcontext.model.Payment;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PaymentRepository extends JpaRepository<Payment, Long> {

}