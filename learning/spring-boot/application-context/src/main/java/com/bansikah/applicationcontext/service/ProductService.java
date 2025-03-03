package com.bansikah.applicationcontext.service;

import org.springframework.stereotype.Service;

@Service
public class ProductService {

    public String getProductName() {
        return "Product Name";
    }

    public String getProductDescription() {
        return "Product Description";
    }

    public String getProductPrice() {
        return "Product Price";
    }

    public String getProductCategory() {
        return "Product Category";
    }

    public String getProductBrand() {
        return "Product Brand";
    }
}
