export interface Restaurant {
  id: number;
  name: string;
  description?: string;
  address?: string;
  phone?: string;
  email?: string;
  logoUrl?: string;
  themeColor?: string;
  createdAt?: string;
  updatedAt?: string;
}

export interface MenuItem {
  id: number;
  name: string;
  description?: string;
  price: number;
  category: string;
  imageUrl?: string;
  available: boolean;
  displayOrder: number;
  createdAt?: string;
}

export interface RestaurantRequest {
  name: string;
  description?: string;
  address?: string;
  phone?: string;
  email?: string;
  logoUrl?: string;
  themeColor?: string;
}

export interface MenuItemRequest {
  name: string;
  description?: string;
  price: number;
  category: string;
  imageUrl?: string;
  available?: boolean;
  displayOrder?: number;
}

export interface QrCodeResponse {
  qrCode: string;
  menuUrl: string;
}

export interface PublicMenuResponse {
  restaurant: Restaurant;
  menuItems: MenuItem[];
}