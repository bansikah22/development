package com.bansikah.applicationcontext.model;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import lombok.Data;

@Entity
@Data
public class Product {

    @Id
    private Long id;

    private String name;

    private String description;

    private String price;

    private String category;

    private String brand;
}
