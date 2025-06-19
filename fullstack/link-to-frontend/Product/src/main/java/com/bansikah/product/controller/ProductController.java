package com.bansikah.product.controller;

import com.bansikah.product.dto.ProductRequest;
import com.bansikah.product.model.Product;
import com.bansikah.product.services.ProductService;
import io.swagger.v3.oas.annotations.tags.Tag;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

@RestController
@RequestMapping("/api/products")
@CrossOrigin(origins = "*")
@Tag(name = "Product API", description = "CRUD operations with image upload and search")
public class ProductController {

    private static final Logger logger = LoggerFactory.getLogger(ProductController.class);

    private final ProductService service;

    public ProductController(ProductService service) {
        this.service = service;
    }

    // 🔹 Create product with optional image
    @PostMapping(consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
    public Product createProduct(
        @RequestParam("name") String name,
        @RequestParam("description") String description,
        @RequestParam("price") double price,
        @RequestPart(value = "image", required = false) MultipartFile image
    ) throws IOException {
        Product productEntity = Product.builder()
                .name(name)
                .description(description)
                .price(price)
                .image(image != null ? image.getBytes() : null)
                .build();

        return service.save(productEntity);
    }

    // 🔹 Get all products
    @GetMapping
    public List<Product> getAll() {
        return service.findAll();
    }

    // 🔹 Get product by ID
    @GetMapping("/{id}")
    public Product getById(@PathVariable Long id) {
        return service.findById(id).orElseThrow(() -> new RuntimeException("Product not found"));
    }

    // 🔹 Update product with optional image
    @PutMapping(value = "/{id}", consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
    public Product update(
            @PathVariable Long id,
            @ModelAttribute ProductRequest product,
            @RequestPart(value = "image", required = false) MultipartFile image
    ) throws IOException {
        Product existing = service.findById(id).orElseThrow(() -> new RuntimeException("Product not found"));
        byte[] imageBytes = image != null ? image.getBytes() : existing.getImage();
        logger.info("[UPDATE] Product {}: imageBytes length before update: {}", id, imageBytes != null ? imageBytes.length : 0);

        Product updatedProduct = Product.builder()
                .name(product.getName())
                .description(product.getDescription())
                .price(product.getPrice())
                .image(imageBytes)
                .build();

        Product result = service.update(id, updatedProduct);
        logger.info("[UPDATE] Product {}: imageBytes length after update: {}", id, result.getImage() != null ? result.getImage().length : 0);
        return result;
    }

    // 🔹 Delete product
    @DeleteMapping("/{id}")
    public void delete(@PathVariable Long id) {
        service.delete(id);
    }

    // 🔹 Search products by name/description
    @GetMapping("/search")
    public List<Product> search(@RequestParam("q") String query) {
        return service.search(query);
    }

    // 🔹 Serve product image
    @GetMapping("/{id}/image")
    public ResponseEntity<byte[]> getImage(@PathVariable Long id) {
        Product product = service.findById(id).orElseThrow(() -> new RuntimeException("Product not found"));
        if (product.getImage() == null) {
            return ResponseEntity.notFound().build();
        }
        return ResponseEntity.ok()
                .contentType(MediaType.IMAGE_JPEG)
                .body(product.getImage());
    }
}
