package com.bansikah.applicationcontext.service;


import org.springframework.stereotype.Service;

@Service
public class GPayPaymentService extends PaymentService {

    @Override
    public String getPaymentServiceName() {
        return "GPay Payment Service";
    }

    @Override
    public String getPaymentServiceDescription() {
        return "GPay Payment Service Description";
    }

    @Override
    public String getPaymentServicePrice() {
        return "GPay Payment Service Price";
    }

    @Override
    public String getPaymentServiceCategory() {
        return "GPay Payment Service Category";
    }

    @Override
    public String getPaymentServiceBrand() {
        return "GPay Payment Service Brand";
    }
}
