package com.bansikah.applicationcontext.service;


import org.springframework.stereotype.Service;

@Service
public class PaymentService {

    public String getPaymentServiceName() {
        return "Payment Service Name";
    }

    public String getPaymentServiceDescription() {
        return "Payment Service Description";
    }

    public String getPaymentServicePrice() {
        return "Payment Service Price";
    }

    public String getPaymentServiceCategory() {
        return "Payment Service Category";
    }

    public String getPaymentServiceBrand() {
        return "Payment Service Brand";
    }
}
