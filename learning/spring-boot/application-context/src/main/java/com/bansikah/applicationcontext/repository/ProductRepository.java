package com.bansikah.applicationcontext.repository;

import com.bansikah.applicationcontext.model.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ProductRepository extends JpaRepository<Product, Long> {


}
