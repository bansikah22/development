package com.qrmenu.mapper;

import com.qrmenu.dto.MenuItemRequest;
import com.qrmenu.dto.RestaurantRequest;
import com.qrmenu.model.MenuItem;
import com.qrmenu.model.Restaurant;
import javax.annotation.processing.Generated;
import org.springframework.stereotype.Component;

@Generated(
    value = "org.mapstruct.ap.MappingProcessor",
    date = "2025-10-11T12:04:38+0100",
    comments = "version: 1.5.5.Final, compiler: javac, environment: Java 17.0.16 (Homebrew)"
)
@Component
public class RestaurantMapperImpl implements RestaurantMapper {

    @Override
    public Restaurant toEntity(RestaurantRequest request) {
        if ( request == null ) {
            return null;
        }

        Restaurant restaurant = new Restaurant();

        restaurant.setName( request.getName() );
        restaurant.setDescription( request.getDescription() );
        restaurant.setAddress( request.getAddress() );
        restaurant.setPhone( request.getPhone() );
        restaurant.setEmail( request.getEmail() );
        restaurant.setLogoUrl( request.getLogoUrl() );
        restaurant.setThemeColor( request.getThemeColor() );

        return restaurant;
    }

    @Override
    public void updateEntity(RestaurantRequest request, Restaurant restaurant) {
        if ( request == null ) {
            return;
        }

        if ( request.getName() != null ) {
            restaurant.setName( request.getName() );
        }
        if ( request.getDescription() != null ) {
            restaurant.setDescription( request.getDescription() );
        }
        if ( request.getAddress() != null ) {
            restaurant.setAddress( request.getAddress() );
        }
        if ( request.getPhone() != null ) {
            restaurant.setPhone( request.getPhone() );
        }
        if ( request.getEmail() != null ) {
            restaurant.setEmail( request.getEmail() );
        }
        if ( request.getLogoUrl() != null ) {
            restaurant.setLogoUrl( request.getLogoUrl() );
        }
        if ( request.getThemeColor() != null ) {
            restaurant.setThemeColor( request.getThemeColor() );
        }
    }

    @Override
    public MenuItem toEntity(MenuItemRequest request) {
        if ( request == null ) {
            return null;
        }

        MenuItem menuItem = new MenuItem();

        menuItem.setName( request.getName() );
        menuItem.setDescription( request.getDescription() );
        menuItem.setPrice( request.getPrice() );
        menuItem.setCategory( request.getCategory() );
        menuItem.setImageUrl( request.getImageUrl() );
        menuItem.setAvailable( request.getAvailable() );
        menuItem.setDisplayOrder( request.getDisplayOrder() );

        return menuItem;
    }

    @Override
    public void updateEntity(MenuItemRequest request, MenuItem menuItem) {
        if ( request == null ) {
            return;
        }

        if ( request.getName() != null ) {
            menuItem.setName( request.getName() );
        }
        if ( request.getDescription() != null ) {
            menuItem.setDescription( request.getDescription() );
        }
        if ( request.getPrice() != null ) {
            menuItem.setPrice( request.getPrice() );
        }
        if ( request.getCategory() != null ) {
            menuItem.setCategory( request.getCategory() );
        }
        if ( request.getImageUrl() != null ) {
            menuItem.setImageUrl( request.getImageUrl() );
        }
        if ( request.getAvailable() != null ) {
            menuItem.setAvailable( request.getAvailable() );
        }
        if ( request.getDisplayOrder() != null ) {
            menuItem.setDisplayOrder( request.getDisplayOrder() );
        }
    }
}
