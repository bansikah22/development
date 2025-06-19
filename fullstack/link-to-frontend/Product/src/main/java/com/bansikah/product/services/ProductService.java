package com.bansikah.product.services;

import com.bansikah.product.model.Product;

import java.util.List;

import com.bansikah.product.repository.ProductRepository;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class ProductService {

    private final ProductRepository repo;

    public ProductService(ProductRepository repo) {
        this.repo = repo;
    }

    public Product save(Product product) {
        return repo.save(product);
    }

    public List<Product> findAll() {
        return repo.findAll();
    }

    public Optional<Product> findById(Long id) {
        return repo.findById(id);
    }

    public Product update(Long id, Product product) {
        return repo.findById(id)
                .map(p -> {
                    p.setName(product.getName());
                    p.setDescription(product.getDescription());
                    p.setPrice(product.getPrice());
                    p.setImage(product.getImage());
                    return repo.save(p);
                })
                .orElseThrow(() -> new RuntimeException("Product not found"));
    }

    public List<Product> search(String query) {
        return repo.findByNameContainingIgnoreCaseOrDescriptionContainingIgnoreCase(query, query);
    }


    public void delete(Long id) {
        repo.deleteById(id);
    }
}
