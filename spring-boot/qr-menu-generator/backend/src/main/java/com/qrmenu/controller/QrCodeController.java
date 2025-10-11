package com.qrmenu.controller;

import com.qrmenu.model.MenuItem;
import com.qrmenu.model.Restaurant;
import com.qrmenu.service.MenuItemService;
import com.qrmenu.service.QrCodeService;
import com.qrmenu.service.RestaurantService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/api")
public class QrCodeController {

    @Autowired
    private QrCodeService qrCodeService;

    @Autowired
    private RestaurantService restaurantService;

    @Autowired
    private MenuItemService menuItemService;

    @GetMapping("/restaurants/{id}/qr-code")
    public ResponseEntity<Map<String, String>> generateQrCode(@PathVariable Long id) {
        try {
            String qrCodeBase64 = qrCodeService.generateQrCode(id);
            String menuUrl = qrCodeService.getMenuUrl(id);
            
            Map<String, String> response = Map.of(
                "qrCode", "data:image/png;base64," + qrCodeBase64,
                "menuUrl", menuUrl
            );
            
            return ResponseEntity.ok(response);
        } catch (Exception e) {
            return ResponseEntity.internalServerError().build();
        }
    }

    @GetMapping("/restaurants/{id}/menu-url")
    public ResponseEntity<Map<String, String>> getMenuUrl(@PathVariable Long id) {
        String menuUrl = qrCodeService.getMenuUrl(id);
        return ResponseEntity.ok(Map.of("menuUrl", menuUrl));
    }

    @GetMapping("/menu/{restaurantId}")
    public ResponseEntity<Map<String, Object>> getPublicMenu(@PathVariable Long restaurantId) {
        try {
            Restaurant restaurant = restaurantService.getRestaurantById(restaurantId)
                    .orElseThrow(() -> new RuntimeException("Restaurant not found"));
            
            List<MenuItem> menuItems = menuItemService.getMenuItemsByRestaurant(restaurantId);
            
            Map<String, Object> response = Map.of(
                "restaurant", restaurant,
                "menuItems", menuItems
            );
            
            return ResponseEntity.ok(response);
        } catch (RuntimeException e) {
            return ResponseEntity.notFound().build();
        }
    }
}