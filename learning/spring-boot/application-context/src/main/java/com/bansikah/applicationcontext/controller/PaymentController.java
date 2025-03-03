package com.bansikah.applicationcontext.controller;

import com.bansikah.applicationcontext.service.CreditCardPaymentService;
import com.bansikah.applicationcontext.service.GPayPaymentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/payments")
public class PaymentController {

    @Autowired
    private CreditCardPaymentService creditCardPaymentService;

    @Autowired
    private GPayPaymentService gpayPaymentService;

    @RequestMapping("/creditcard")
    public String processCreditCardPayment() {
        return creditCardPaymentService.getPaymentServiceName();
    }

    @RequestMapping("/gpay")
    public String processGPayPayment() {
        return gpayPaymentService.getPaymentServiceName();
    }
}