import { useState, useEffect } from 'react';
import { Building2, QrCode, Menu, ArrowLeft } from 'lucide-react';
import RestaurantForm from './components/RestaurantForm';
import MenuItemForm from './components/MenuItemForm';
import MenuDisplay from './components/MenuDisplay';
import QrCodeDisplay from './components/QrCodeDisplay';
import CustomerMenuView from './components/CustomerMenuView';
import { restaurantApi, menuItemApi, qrCodeApi } from './services/api';
import type { Restaurant as RestaurantType, MenuItem, RestaurantRequest, MenuItemRequest, QrCodeResponse } from './types';

type AppView = 'restaurant' | 'menu' | 'qrcode' | 'customer-menu';

function App() {
  const [currentView, setCurrentView] = useState<AppView>('restaurant');
  const [restaurant, setRestaurant] = useState<RestaurantType | null>(null);
  const [menuItems, setMenuItems] = useState<MenuItem[]>([]);
  const [qrData, setQrData] = useState<QrCodeResponse | null>(null);
  const [editingItem, setEditingItem] = useState<MenuItem | null>(null);
  const [showItemForm, setShowItemForm] = useState(false);
  const [isLoading, setIsLoading] = useState(false);

  // Load restaurant data if exists
  useEffect(() => {
    loadRestaurantData();
  }, []);

  const loadRestaurantData = async () => {
    try {
      const restaurants = await restaurantApi.getAll();
      if (restaurants.length > 0) {
        const firstRestaurant = restaurants[0];
        setRestaurant(firstRestaurant);
        loadMenuItems(firstRestaurant.id);
      }
    } catch (error) {
      console.error('Error loading restaurant data:', error);
    }
  };

  const loadMenuItems = async (restaurantId: number) => {
    try {
      const items = await menuItemApi.getByRestaurant(restaurantId);
      setMenuItems(items);
    } catch (error) {
      console.error('Error loading menu items:', error);
    }
  };

  const handleRestaurantSubmit = async (data: RestaurantRequest) => {
    setIsLoading(true);
    try {
      let savedRestaurant;
      if (restaurant) {
        savedRestaurant = await restaurantApi.update(restaurant.id, data);
      } else {
        savedRestaurant = await restaurantApi.create(data);
      }
      setRestaurant(savedRestaurant);
      setCurrentView('menu');
    } catch (error) {
      console.error('Error saving restaurant:', error);
    } finally {
      setIsLoading(false);
    }
  };

  const handleMenuItemSubmit = async (data: MenuItemRequest) => {
    if (!restaurant) return;
    
    setIsLoading(true);
    try {
      if (editingItem) {
        await menuItemApi.update(editingItem.id, data);
      } else {
        await menuItemApi.create(restaurant.id, data);
      }
      await loadMenuItems(restaurant.id);
      setEditingItem(null);
      setShowItemForm(false);
    } catch (error) {
      console.error('Error saving menu item:', error);
    } finally {
      setIsLoading(false);
    }
  };

  const handleDeleteItem = async (id: number) => {
    if (!restaurant || !window.confirm('Are you sure you want to delete this item?')) return;
    
    try {
      await menuItemApi.delete(id);
      await loadMenuItems(restaurant.id);
    } catch (error) {
      console.error('Error deleting menu item:', error);
    }
  };

  const handleGenerateQR = async () => {
    if (!restaurant) return;
    
    setIsLoading(true);
    try {
      const qrResponse = await qrCodeApi.generate(restaurant.id);
      setQrData(qrResponse);
      setCurrentView('qrcode');
    } catch (error) {
      console.error('Error generating QR code:', error);
    } finally {
      setIsLoading(false);
    }
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-rose-50 via-orange-50 to-amber-50">
      {/* Modern Navigation Header */}
      <nav className="bg-white/90 backdrop-blur-lg shadow-sm border-b border-orange-200/50 sticky top-0 z-50">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="flex justify-between items-center h-16">
            <div className="flex items-center">
              <div className="h-10 w-10 bg-gradient-to-br from-orange-400 to-rose-500 rounded-xl flex items-center justify-center mr-3 shadow-lg">
                <QrCode className="h-5 w-5 text-white" />
              </div>
              <div>
                <h1 className="text-xl font-bold bg-gradient-to-r from-gray-800 to-orange-600 bg-clip-text text-transparent">
                  QR Menu Generator
                </h1>
                <p className="text-xs text-orange-600/70 -mt-1">Create beautiful digital menus</p>
              </div>
            </div>
            
            {restaurant && (
              <div className="flex items-center bg-orange-100/70 rounded-xl p-1.5 space-x-1">
                <button
                  onClick={() => setCurrentView('restaurant')}
                  className={`px-4 py-2 rounded-lg font-medium text-sm transition-all duration-200 ${
                    currentView === 'restaurant'
                      ? 'bg-white text-orange-800 shadow-md'
                      : 'text-orange-700 hover:text-orange-800 hover:bg-white/70'
                  }`}
                >
                  <Building2 className="w-4 h-4 mr-2 inline" />
                  Restaurant
                </button>
                <button
                  onClick={() => setCurrentView('menu')}
                  className={`px-4 py-2 rounded-lg font-medium text-sm transition-all duration-200 ${
                    currentView === 'menu'
                      ? 'bg-white text-orange-800 shadow-md'
                      : 'text-orange-700 hover:text-orange-800 hover:bg-white/70'
                  }`}
                >
                  <Menu className="w-4 h-4 mr-2 inline" />
                  Menu Items
                </button>
                {menuItems.length > 0 && (
                  <button
                    onClick={handleGenerateQR}
                    className={`px-4 py-2 rounded-lg font-medium text-sm transition-all duration-200 ${
                      currentView === 'qrcode'
                        ? 'bg-white text-orange-800 shadow-md'
                        : 'text-orange-700 hover:text-orange-800 hover:bg-white/70'
                    } ${isLoading ? 'opacity-50 cursor-not-allowed' : ''}`}
                    disabled={isLoading}
                  >
                    <QrCode className="w-4 h-4 mr-2 inline" />
                    Generate QR
                  </button>
                )}
              </div>
            )}
          </div>
        </div>
      </nav>

      {/* Main Content */}
      <main className="min-h-screen flex items-center justify-center py-12 px-4 sm:px-6 lg:px-8">
        <div className="w-full">
          {/* Restaurant Form */}
          {currentView === 'restaurant' && (
            <div className="max-w-2xl mx-auto">
              <RestaurantForm
                onSubmit={handleRestaurantSubmit}
                initialData={restaurant ? {
                  name: restaurant.name || '',
                  description: restaurant.description || '',
                  address: restaurant.address || '',
                  phone: restaurant.phone || '',
                  email: restaurant.email || '',
                  logoUrl: restaurant.logoUrl || '',
                  themeColor: restaurant.themeColor || '#3B82F6'
                } : undefined}
                isLoading={isLoading}
              />
            </div>
          )}          {/* Menu Management */}
          {currentView === 'menu' && restaurant && (
            <div className="max-w-4xl mx-auto">
              {showItemForm ? (
                <div>
                  <button
                    onClick={() => {
                      setShowItemForm(false);
                      setEditingItem(null);
                    }}
                    className="mb-4 flex items-center text-orange-600 hover:text-orange-800 transition-colors duration-200"
                  >
                    <ArrowLeft className="w-4 h-4 mr-1" />
                    Back to Menu
                  </button>
                  <MenuItemForm
                    onSubmit={handleMenuItemSubmit}
                    initialData={editingItem ? {
                      name: editingItem.name,
                      description: editingItem.description || '',
                      price: editingItem.price,
                      category: editingItem.category,
                      imageUrl: editingItem.imageUrl || '',
                      available: editingItem.available,
                      displayOrder: editingItem.displayOrder
                    } : undefined}
                    isLoading={isLoading}
                    onCancel={() => {
                      setShowItemForm(false);
                      setEditingItem(null);
                    }}
                  />
                </div>
              ) : (
                <MenuDisplay
                  menuItems={menuItems}
                  onEditItem={(item) => {
                    setEditingItem(item);
                    setShowItemForm(true);
                  }}
                  onDeleteItem={handleDeleteItem}
                  onAddItem={() => setShowItemForm(true)}
                  isLoading={isLoading}
                />
              )}
            </div>
          )}

          {/* QR Code Display */}
          {currentView === 'qrcode' && qrData && restaurant && (
            <div className="max-w-2xl mx-auto">
              <QrCodeDisplay
                qrData={qrData}
                restaurantName={restaurant.name}
                onPreviewMenu={() => setCurrentView('customer-menu')}
              />
            </div>
          )}

          {/* Customer Menu Preview */}
          {currentView === 'customer-menu' && restaurant && (
            <div className="relative max-w-4xl mx-auto">
              <div className="mb-6 flex items-center">
                <button
                  onClick={() => setCurrentView('qrcode')}
                  className="flex items-center text-orange-600 hover:text-orange-800 transition-colors duration-200"
                >
                  <ArrowLeft className="w-4 h-4 mr-2" />
                  Back to QR Code
                </button>
              </div>
              <div className="bg-white rounded-2xl shadow-xl border border-orange-200/60 overflow-hidden">
                <div className="p-6 border-b border-orange-200/60 bg-gradient-to-r from-orange-50 to-amber-50">
                  <h2 className="text-xl font-bold text-orange-800 text-center">Customer Menu Preview</h2>
                  <p className="text-orange-600 text-center text-sm mt-1">This is how your menu will appear to customers</p>
                </div>
                <div className="max-h-96 overflow-y-auto">
                  <CustomerMenuView
                    restaurant={restaurant as RestaurantType}
                    menuItems={menuItems}
                  />
                </div>
              </div>
            </div>
          )}

          {/* Modern Welcome Section */}
          {!restaurant && currentView === 'restaurant' && (
            <div className="text-center mb-12 py-16">
              <div className="relative">
                <div className="absolute inset-0 bg-gradient-to-r from-blue-500/10 via-purple-500/10 to-pink-500/10 blur-3xl"></div>
                <div className="relative">
                  <div className="h-20 w-20 bg-gradient-to-br from-blue-500 to-purple-600 rounded-2xl mx-auto mb-8 flex items-center justify-center shadow-2xl">
                    <QrCode className="h-10 w-10 text-white" />
                  </div>
                  <h2 className="text-4xl md:text-6xl font-bold bg-gradient-to-r from-slate-800 via-slate-600 to-slate-800 bg-clip-text text-transparent mb-6 leading-tight">
                    Welcome to QR Menu Generator
                  </h2>
                  <p className="text-xl text-slate-600 max-w-2xl mx-auto leading-relaxed">
                    Transform your restaurant experience with beautiful, digital menus that customers can access instantly with a simple QR code scan.
                  </p>
                  <div className="mt-8 flex flex-wrap justify-center gap-6 text-sm text-slate-500">
                    <div className="flex items-center gap-2">
                      <div className="w-2 h-2 bg-green-500 rounded-full"></div>
                      <span>Easy Setup</span>
                    </div>
                    <div className="flex items-center gap-2">
                      <div className="w-2 h-2 bg-blue-500 rounded-full"></div>
                      <span>Mobile Friendly</span>
                    </div>
                    <div className="flex items-center gap-2">
                      <div className="w-2 h-2 bg-purple-500 rounded-full"></div>
                      <span>Instant Updates</span>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          )}
        </div>
      </main>
    </div>
  );
}

export default App;
