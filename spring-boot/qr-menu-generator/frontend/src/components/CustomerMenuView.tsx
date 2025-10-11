import React from 'react';
import { Clock, Star, MapPin, Phone, Mail } from 'lucide-react';
import type { Restaurant, MenuItem } from '../types';

interface CustomerMenuViewProps {
  restaurant: Restaurant;
  menuItems: MenuItem[];
}

const CustomerMenuView: React.FC<CustomerMenuViewProps> = ({ restaurant, menuItems }) => {
  // Group items by category
  const groupedItems = menuItems.reduce((acc, item) => {
    if (!acc[item.category]) {
      acc[item.category] = [];
    }
    acc[item.category].push(item);
    return acc;
  }, {} as Record<string, MenuItem[]>);

  const formatPrice = (price: number) => {
    return new Intl.NumberFormat('en-US', {
      style: 'currency',
      currency: 'USD',
    }).format(price);
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-slate-50 via-white to-slate-100">
      {/* Header */}
      <div className="relative overflow-hidden bg-gradient-to-r from-slate-900 via-slate-800 to-slate-900">
        <div className="absolute inset-0 bg-[radial-gradient(circle_at_50%_120%,rgba(120,119,198,0.3),rgba(255,255,255,0))]"></div>
        <div className="relative max-w-4xl mx-auto px-6 py-12 text-center">
          {restaurant.logoUrl && (
            <div className="mb-6">
              <img 
                src={restaurant.logoUrl} 
                alt={restaurant.name}
                className="h-16 w-16 mx-auto rounded-full object-cover border-4 border-white/20 shadow-lg"
              />
            </div>
          )}
          <h1 className="text-4xl md:text-6xl font-bold text-white mb-4 tracking-tight">
            {restaurant.name}
          </h1>
          {restaurant.description && (
            <p className="text-xl text-slate-300 mb-6 max-w-2xl mx-auto leading-relaxed">
              {restaurant.description}
            </p>
          )}
          
          {/* Contact Info */}
          <div className="flex flex-wrap justify-center gap-6 text-slate-300">
            {restaurant.address && (
              <div className="flex items-center gap-2">
                <MapPin className="w-4 h-4" />
                <span className="text-sm">{restaurant.address}</span>
              </div>
            )}
            {restaurant.phone && (
              <div className="flex items-center gap-2">
                <Phone className="w-4 h-4" />
                <span className="text-sm">{restaurant.phone}</span>
              </div>
            )}
            {restaurant.email && (
              <div className="flex items-center gap-2">
                <Mail className="w-4 h-4" />
                <span className="text-sm">{restaurant.email}</span>
              </div>
            )}
          </div>
        </div>
      </div>

      {/* Menu Content */}
      <div className="max-w-4xl mx-auto px-6 py-12">
        {Object.keys(groupedItems).length === 0 ? (
          <div className="text-center py-16">
            <div className="w-24 h-24 mx-auto mb-6 bg-slate-100 rounded-full flex items-center justify-center">
              <Clock className="w-8 h-8 text-slate-400" />
            </div>
            <h2 className="text-2xl font-semibold text-slate-700 mb-2">Menu Coming Soon</h2>
            <p className="text-slate-500">Our delicious menu is being prepared. Please check back soon!</p>
          </div>
        ) : (
          <div className="space-y-12">
            {Object.entries(groupedItems).map(([category, items]) => (
              <section key={category} className="space-y-6">
                <div className="text-center">
                  <h2 className="text-3xl md:text-4xl font-bold text-slate-800 mb-2">
                    {category}
                  </h2>
                  <div className="w-24 h-1 bg-gradient-to-r from-transparent via-slate-300 to-transparent mx-auto"></div>
                </div>
                
                <div className="grid gap-6 md:gap-8">
                  {items
                    .filter(item => item.available)
                    .sort((a, b) => (a.displayOrder || 0) - (b.displayOrder || 0))
                    .map((item) => (
                    <div 
                      key={item.id}
                      className="group bg-white rounded-2xl shadow-sm border border-slate-200/50 overflow-hidden hover:shadow-lg transition-all duration-300 hover:-translate-y-1"
                    >
                      <div className="p-6 md:p-8">
                        <div className="flex flex-col md:flex-row gap-6">
                          {/* Image */}
                          {item.imageUrl && (
                            <div className="flex-shrink-0">
                              <img 
                                src={item.imageUrl} 
                                alt={item.name}
                                className="w-full md:w-24 md:h-24 object-cover rounded-xl group-hover:scale-105 transition-transform duration-300"
                              />
                            </div>
                          )}
                          
                          {/* Content */}
                          <div className="flex-1 min-w-0">
                            <div className="flex items-start justify-between gap-4 mb-3">
                              <h3 className="text-xl md:text-2xl font-semibold text-slate-800 leading-tight">
                                {item.name}
                              </h3>
                              <div className="flex-shrink-0">
                                <span className="text-2xl font-bold text-emerald-600">
                                  {formatPrice(item.price)}
                                </span>
                              </div>
                            </div>
                            
                            {item.description && (
                              <p className="text-slate-600 leading-relaxed">
                                {item.description}
                              </p>
                            )}
                          </div>
                        </div>
                      </div>
                    </div>
                  ))}
                </div>
              </section>
            ))}
          </div>
        )}
      </div>

      {/* Footer */}
      <footer className="bg-slate-900 text-slate-300 py-8 mt-16">
        <div className="max-w-4xl mx-auto px-6 text-center">
          <div className="flex items-center justify-center gap-2 mb-4">
            <Star className="w-5 h-5 text-yellow-400 fill-current" />
            <span className="font-medium">Thank you for dining with us!</span>
            <Star className="w-5 h-5 text-yellow-400 fill-current" />
          </div>
          <p className="text-sm text-slate-400">
            Menu generated at {new Date().toLocaleDateString()}
          </p>
        </div>
      </footer>
    </div>
  );
};

export default CustomerMenuView;