package com.bansikah.applicationcontext.controller;

import com.bansikah.applicationcontext.service.ProductService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/products")
public class ProductController {

    @Autowired
    private ProductService productService;

    @RequestMapping("/get")
    public String getProduct() {
        return productService.getProductName();
    }

    @RequestMapping("/get/description")
    public String getProductDescription() {
        return productService.getProductDescription();
    }

    @RequestMapping("/get/price")
    public String getProductPrice() {
        return productService.getProductPrice();
    }


}
