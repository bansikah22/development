# API Reference Guide

## Base URL

The API base URL depends on your deployment environment:

- **Development**: `http://localhost:8080/api`
- **Production**: `https://yourdomain.com/api`

## Authentication

Currently, the API does not require authentication. This is designed for MVP deployment where restaurant owners manage their own instances.

## Response Format

All API responses follow a consistent JSON format:

### Success Response
```json
{
  "data": "response data here",
  "status": "success"
}
```

### Error Response
```json
{
  "timestamp": "2025-10-11T12:00:00.000+00:00",
  "status": 400,
  "error": "Bad Request",
  "message": "Validation failed",
  "path": "/api/restaurants"
}
```

## Restaurant Management

### Create Restaurant

Creates a new restaurant with the provided information.

**Endpoint**: `POST /api/restaurants`

**Request Headers**:
```
Content-Type: application/json
```

**Request Body**:
```json
{
  "name": "Greedy Fast Food",
  "description": "Best fast food in town",
  "address": "123 Main Street, City, Country",
  "phone": "+1234567890",
  "email": "contact@greedy.com",
  "themeColor": "#ea580c"
}
```

**Response**: `201 Created`
```json
{
  "id": 1,
  "name": "Greedy Fast Food",
  "description": "Best fast food in town",
  "address": "123 Main Street, City, Country",
  "phone": "+1234567890",
  "email": "contact@greedy.com",
  "logoUrl": null,
  "themeColor": "#ea580c",
  "createdAt": "2025-10-11T12:00:00.000+00:00",
  "updatedAt": "2025-10-11T12:00:00.000+00:00",
  "menuItems": []
}
```

### Get All Restaurants

Retrieves a list of all restaurants.

**Endpoint**: `GET /api/restaurants`

**Response**: `200 OK`
```json
[
  {
    "id": 1,
    "name": "Greedy Fast Food",
    "description": "Best fast food in town",
    "address": "123 Main Street, City, Country",
    "phone": "+1234567890",
    "email": "contact@greedy.com",
    "logoUrl": null,
    "themeColor": "#ea580c",
    "createdAt": "2025-10-11T12:00:00.000+00:00",
    "updatedAt": "2025-10-11T12:00:00.000+00:00",
    "menuItems": [...]
  }
]
```

### Get Restaurant by ID

Retrieves a specific restaurant by its ID.

**Endpoint**: `GET /api/restaurants/{id}`

**Path Parameters**:
- `id` (integer): Restaurant ID

**Response**: `200 OK`
```json
{
  "id": 1,
  "name": "Greedy Fast Food",
  "description": "Best fast food in town",
  "address": "123 Main Street, City, Country",
  "phone": "+1234567890",
  "email": "contact@greedy.com",
  "logoUrl": null,
  "themeColor": "#ea580c",
  "createdAt": "2025-10-11T12:00:00.000+00:00",
  "updatedAt": "2025-10-11T12:00:00.000+00:00",
  "menuItems": [...]
}
```

**Error Response**: `404 Not Found`
```json
{
  "timestamp": "2025-10-11T12:00:00.000+00:00",
  "status": 404,
  "error": "Not Found",
  "message": "Restaurant not found with id: 999",
  "path": "/api/restaurants/999"
}
```

### Update Restaurant

Updates an existing restaurant's information.

**Endpoint**: `PUT /api/restaurants/{id}`

**Path Parameters**:
- `id` (integer): Restaurant ID

**Request Headers**:
```
Content-Type: application/json
```

**Request Body**:
```json
{
  "name": "Updated Restaurant Name",
  "description": "Updated description",
  "address": "Updated address",
  "phone": "Updated phone",
  "email": "updated@email.com",
  "themeColor": "#f59e0b"
}
```

**Response**: `200 OK`
```json
{
  "id": 1,
  "name": "Updated Restaurant Name",
  "description": "Updated description",
  "address": "Updated address",
  "phone": "Updated phone",
  "email": "updated@email.com",
  "logoUrl": null,
  "themeColor": "#f59e0b",
  "createdAt": "2025-10-11T12:00:00.000+00:00",
  "updatedAt": "2025-10-11T12:30:00.000+00:00",
  "menuItems": [...]
}
```

### Delete Restaurant

Deletes a restaurant and all associated menu items.

**Endpoint**: `DELETE /api/restaurants/{id}`

**Path Parameters**:
- `id` (integer): Restaurant ID

**Response**: `204 No Content`

## Menu Item Management

### Add Menu Item

Adds a new menu item to a restaurant.

**Endpoint**: `POST /api/restaurants/{restaurantId}/menu-items`

**Path Parameters**:
- `restaurantId` (integer): Restaurant ID

**Request Headers**:
```
Content-Type: application/json
```

**Request Body**:
```json
{
  "name": "Deluxe Burger",
  "description": "Juicy beef patty with premium toppings",
  "price": 15.99,
  "category": "Main Course",
  "imageUrl": "https://example.com/burger.jpg",
  "available": true
}
```

**Response**: `201 Created`
```json
{
  "id": 1,
  "name": "Deluxe Burger",
  "description": "Juicy beef patty with premium toppings",
  "price": 15.99,
  "category": "Main Course",
  "imageUrl": "https://example.com/burger.jpg",
  "available": true,
  "displayOrder": 1,
  "createdAt": "2025-10-11T12:00:00.000+00:00"
}
```

### Get Menu Items

Retrieves all menu items for a restaurant.

**Endpoint**: `GET /api/restaurants/{restaurantId}/menu-items`

**Path Parameters**:
- `restaurantId` (integer): Restaurant ID

**Response**: `200 OK`
```json
[
  {
    "id": 1,
    "name": "Deluxe Burger",
    "description": "Juicy beef patty with premium toppings",
    "price": 15.99,
    "category": "Main Course",
    "imageUrl": "https://example.com/burger.jpg",
    "available": true,
    "displayOrder": 1,
    "createdAt": "2025-10-11T12:00:00.000+00:00"
  },
  {
    "id": 2,
    "name": "Caesar Salad",
    "description": "Fresh romaine lettuce with caesar dressing",
    "price": 8.99,
    "category": "Salads",
    "imageUrl": "https://example.com/salad.jpg",
    "available": true,
    "displayOrder": 2,
    "createdAt": "2025-10-11T12:05:00.000+00:00"
  }
]
```

### Update Menu Item

Updates an existing menu item.

**Endpoint**: `PUT /api/menu-items/{itemId}`

**Path Parameters**:
- `itemId` (integer): Menu item ID

**Request Headers**:
```
Content-Type: application/json
```

**Request Body**:
```json
{
  "name": "Updated Burger Name",
  "description": "Updated description",
  "price": 17.99,
  "category": "Updated Category",
  "imageUrl": "https://example.com/updated-image.jpg",
  "available": false
}
```

**Response**: `200 OK`
```json
{
  "id": 1,
  "name": "Updated Burger Name",
  "description": "Updated description",
  "price": 17.99,
  "category": "Updated Category",
  "imageUrl": "https://example.com/updated-image.jpg",
  "available": false,
  "displayOrder": 1,
  "createdAt": "2025-10-11T12:00:00.000+00:00"
}
```

### Delete Menu Item

Deletes a menu item from a restaurant.

**Endpoint**: `DELETE /api/menu-items/{itemId}`

**Path Parameters**:
- `itemId` (integer): Menu item ID

**Response**: `204 No Content`

## QR Code Generation

### Generate QR Code

Generates a QR code for a restaurant's menu.

**Endpoint**: `GET /api/restaurants/{id}/qr-code`

**Path Parameters**:
- `id` (integer): Restaurant ID

**Response**: `200 OK`
```json
{
  "qrCode": "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAASwAAAEsAQAAAABRBrPYAAABnUlEQVR4Xu2ZMX...",
  "menuUrl": "https://yourdomain.com/api/menu/1"
}
```

**Response Fields**:
- `qrCode`: Base64-encoded PNG image of the QR code
- `menuUrl`: The URL that the QR code points to

## Customer Menu Access

### Get Public Menu

Provides the complete menu information for customers who scan the QR code.

**Endpoint**: `GET /api/menu/{restaurantId}`

**Path Parameters**:
- `restaurantId` (integer): Restaurant ID

**Response**: `200 OK`
```json
{
  "restaurant": {
    "id": 1,
    "name": "Greedy Fast Food",
    "description": "Best fast food in town",
    "address": "123 Main Street, City, Country",
    "phone": "+1234567890",
    "email": "contact@greedy.com",
    "logoUrl": null,
    "themeColor": "#ea580c"
  },
  "menuItems": [
    {
      "id": 1,
      "name": "Deluxe Burger",
      "description": "Juicy beef patty with premium toppings",
      "price": 15.99,
      "category": "Main Course",
      "imageUrl": "https://example.com/burger.jpg",
      "available": true,
      "displayOrder": 1
    }
  ]
}
```

## Error Handling

### Common HTTP Status Codes

- **200 OK**: Request successful
- **201 Created**: Resource created successfully
- **204 No Content**: Request successful with no response body
- **400 Bad Request**: Invalid request data
- **404 Not Found**: Resource not found
- **500 Internal Server Error**: Server error

### Validation Errors

When validation fails, the API returns detailed error information:

**Response**: `400 Bad Request`
```json
{
  "timestamp": "2025-10-11T12:00:00.000+00:00",
  "status": 400,
  "error": "Bad Request",
  "message": "Validation failed",
  "path": "/api/restaurants",
  "errors": [
    {
      "field": "name",
      "message": "Restaurant name is required"
    },
    {
      "field": "email",
      "message": "Invalid email format"
    }
  ]
}
```

## Rate Limiting

Currently, no rate limiting is implemented. For production deployments with high traffic, consider implementing rate limiting at the nginx or application level.

## CORS Configuration

The API is configured to accept requests from allowed origins based on environment variables:

- **Development**: Allows localhost origins
- **Production**: Allows requests from the configured `FRONTEND_URL`

## Data Validation Rules

### Restaurant Validation
- `name`: Required, 1-100 characters
- `description`: Optional, max 500 characters  
- `address`: Required, max 200 characters
- `phone`: Required, valid phone format
- `email`: Required, valid email format
- `themeColor`: Optional, valid hex color code

### Menu Item Validation
- `name`: Required, 1-100 characters
- `description`: Optional, max 300 characters
- `price`: Required, positive decimal number
- `category`: Required, 1-50 characters
- `imageUrl`: Optional, valid URL format
- `available`: Required, boolean value

## Database Schema

### Restaurant Table
```sql
CREATE TABLE restaurants (
    id BIGSERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    description TEXT,
    address VARCHAR(255) NOT NULL,
    phone VARCHAR(50) NOT NULL,
    email VARCHAR(255) NOT NULL,
    logo_url VARCHAR(500),
    theme_color VARCHAR(7),
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);
```

### Menu Item Table
```sql
CREATE TABLE menu_items (
    id BIGSERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    description TEXT,
    price DECIMAL(10,2) NOT NULL,
    category VARCHAR(255) NOT NULL,
    image_url VARCHAR(500),
    available BOOLEAN NOT NULL DEFAULT true,
    display_order INTEGER,
    restaurant_id BIGINT NOT NULL,
    created_at TIMESTAMP NOT NULL,
    FOREIGN KEY (restaurant_id) REFERENCES restaurants(id) ON DELETE CASCADE
);
```