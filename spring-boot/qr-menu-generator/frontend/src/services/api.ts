import axios from 'axios';
import type { Restaurant, MenuItem, RestaurantRequest, MenuItemRequest, QrCodeResponse, PublicMenuResponse } from '../types';

// Smart API URL detection for different environments
const getApiBaseUrl = (): string => {
  // Check for explicit environment variable first
  if (import.meta.env.VITE_API_BASE_URL) {
    return import.meta.env.VITE_API_BASE_URL;
  }

  // Auto-detect based on current host
  const currentHost = window.location.host;
  const protocol = window.location.protocol;
  
  // Development environment detection
  if (currentHost.includes('localhost') || currentHost.includes('127.0.0.1')) {
    if (currentHost.includes(':5173') || currentHost.includes(':5174') || currentHost.includes(':3000')) {
      // Development mode - Vite dev server
      return 'http://localhost:8080/api';
    }
    // Docker Compose local
    return 'http://localhost:8080/api';
  }
  
  // Production environment - use same host with /api path
  // This works for most deployment scenarios (nginx proxy, ALB, etc.)
  return `${protocol}//${currentHost}/api`;
};

const API_BASE_URL = getApiBaseUrl();

const api = axios.create({
  baseURL: API_BASE_URL,
  headers: {
    'Content-Type': 'application/json',
  },
});

// Restaurant API calls
export const restaurantApi = {
  getAll: (): Promise<Restaurant[]> => api.get('/restaurants').then(res => res.data),
  getById: (id: number): Promise<Restaurant> => api.get(`/restaurants/${id}`).then(res => res.data),
  create: (restaurant: RestaurantRequest): Promise<Restaurant> => api.post('/restaurants', restaurant).then(res => res.data),
  update: (id: number, restaurant: RestaurantRequest): Promise<Restaurant> => api.put(`/restaurants/${id}`, restaurant).then(res => res.data),
  delete: (id: number): Promise<void> => api.delete(`/restaurants/${id}`).then(res => res.data),
};

// Menu Item API calls
export const menuItemApi = {
  getByRestaurant: (restaurantId: number): Promise<MenuItem[]> => api.get(`/restaurants/${restaurantId}/menu-items`).then(res => res.data),
  getById: (id: number): Promise<MenuItem> => api.get(`/menu-items/${id}`).then(res => res.data),
  create: (restaurantId: number, menuItem: MenuItemRequest): Promise<MenuItem> => api.post(`/restaurants/${restaurantId}/menu-items`, menuItem).then(res => res.data),
  update: (id: number, menuItem: MenuItemRequest): Promise<MenuItem> => api.put(`/menu-items/${id}`, menuItem).then(res => res.data),
  delete: (id: number): Promise<void> => api.delete(`/menu-items/${id}`).then(res => res.data),
};

// QR Code API calls
export const qrCodeApi = {
  generate: (restaurantId: number): Promise<QrCodeResponse> => api.get(`/restaurants/${restaurantId}/qr-code`).then(res => res.data),
  getMenuUrl: (restaurantId: number): Promise<{ menuUrl: string }> => api.get(`/restaurants/${restaurantId}/menu-url`).then(res => res.data),
  getPublicMenu: (restaurantId: number): Promise<PublicMenuResponse> => api.get(`/menu/${restaurantId}`).then(res => res.data),
};

export default api;