package com.bansikah.applicationcontext.service;

import org.springframework.stereotype.Service;

@Service
public class CreditCardPaymentService extends PaymentService {

    @Override
    public String getPaymentServiceName() {
        return "Credit Card Payment Service";
    }

    @Override
    public String getPaymentServiceDescription() {
        return "Credit Card Payment Service Description";
    }

    @Override
    public String getPaymentServicePrice() {
        return "Credit Card Payment Service Price";
    }

    @Override
    public String getPaymentServiceCategory() {
        return "Credit Card Payment Service Category";
    }

    @Override
    public String getPaymentServiceBrand() {
        return "Credit Card Payment Service Brand";
    }
}
