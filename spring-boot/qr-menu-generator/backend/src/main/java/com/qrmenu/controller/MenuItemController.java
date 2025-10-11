package com.qrmenu.controller;

import com.qrmenu.dto.MenuItemRequest;
import com.qrmenu.model.MenuItem;
import com.qrmenu.service.MenuItemService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api")
public class MenuItemController {

    @Autowired
    private MenuItemService menuItemService;

    @GetMapping("/restaurants/{restaurantId}/menu-items")
    public ResponseEntity<List<MenuItem>> getMenuItemsByRestaurant(@PathVariable Long restaurantId) {
        try {
            List<MenuItem> menuItems = menuItemService.getMenuItemsByRestaurant(restaurantId);
            return ResponseEntity.ok(menuItems);
        } catch (RuntimeException e) {
            return ResponseEntity.notFound().build();
        }
    }

    @GetMapping("/menu-items/{id}")
    public ResponseEntity<MenuItem> getMenuItemById(@PathVariable Long id) {
        return menuItemService.getMenuItemById(id)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @PostMapping("/restaurants/{restaurantId}/menu-items")
    public ResponseEntity<MenuItem> createMenuItem(@PathVariable Long restaurantId,
                                                 @Valid @RequestBody MenuItemRequest request) {
        try {
            MenuItem menuItem = menuItemService.createMenuItem(restaurantId, request);
            return ResponseEntity.ok(menuItem);
        } catch (RuntimeException e) {
            return ResponseEntity.notFound().build();
        }
    }

    @PutMapping("/menu-items/{id}")
    public ResponseEntity<MenuItem> updateMenuItem(@PathVariable Long id,
                                                 @Valid @RequestBody MenuItemRequest request) {
        try {
            MenuItem menuItem = menuItemService.updateMenuItem(id, request);
            return ResponseEntity.ok(menuItem);
        } catch (RuntimeException e) {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/menu-items/{id}")
    public ResponseEntity<Void> deleteMenuItem(@PathVariable Long id) {
        menuItemService.deleteMenuItem(id);
        return ResponseEntity.noContent().build();
    }
}