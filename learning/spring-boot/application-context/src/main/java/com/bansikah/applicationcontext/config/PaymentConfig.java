package com.bansikah.applicationcontext.config;

import com.bansikah.applicationcontext.service.CreditCardPaymentService;
import com.bansikah.applicationcontext.service.GPayPaymentService;
import com.bansikah.applicationcontext.service.PaymentService;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class PaymentConfig {

    // TODO: Add a bean of type PaymentService
    @Bean(name = "customCreditCardPaymentService")
    public CreditCardPaymentService creditCardPaymentService() {
        return new CreditCardPaymentService();
    }

    @Bean
    public PaymentService gpayPaymentService() {
        return new GPayPaymentService();
    }


}
