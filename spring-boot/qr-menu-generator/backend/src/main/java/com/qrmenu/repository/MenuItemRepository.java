package com.qrmenu.repository;

import com.qrmenu.model.MenuItem;
import com.qrmenu.model.Restaurant;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface MenuItemRepository extends JpaRepository<MenuItem, Long> {
    List<MenuItem> findByRestaurantOrderByDisplayOrderAsc(Restaurant restaurant);
    List<MenuItem> findByRestaurantAndCategoryOrderByDisplayOrderAsc(Restaurant restaurant, String category);
}