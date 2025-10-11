package com.qrmenu.mapper;

import com.qrmenu.dto.RestaurantRequest;
import com.qrmenu.dto.MenuItemRequest;
import com.qrmenu.model.Restaurant;
import com.qrmenu.model.MenuItem;
import org.mapstruct.Mapper;
import org.mapstruct.MappingTarget;
import org.mapstruct.NullValuePropertyMappingStrategy;

@Mapper(componentModel = "spring", 
        nullValuePropertyMappingStrategy = NullValuePropertyMappingStrategy.IGNORE)
public interface RestaurantMapper {
    
    Restaurant toEntity(RestaurantRequest request);
    
    void updateEntity(RestaurantRequest request, @MappingTarget Restaurant restaurant);
    
    MenuItem toEntity(MenuItemRequest request);
    
    void updateEntity(MenuItemRequest request, @MappingTarget MenuItem menuItem);
}