import React from 'react';
import { Edit, Trash2, Plus } from 'lucide-react';
import type { MenuItem } from '../types';

interface MenuDisplayProps {
  menuItems: MenuItem[];
  onEditItem: (item: MenuItem) => void;
  onDeleteItem: (id: number) => void;
  onAddItem: () => void;
  isLoading?: boolean;
}

const MenuDisplay: React.FC<MenuDisplayProps> = ({ 
  menuItems, 
  onEditItem, 
  onDeleteItem, 
  onAddItem,
  isLoading = false 
}) => {
  const groupedItems = menuItems.reduce((acc, item) => {
    if (!acc[item.category]) {
      acc[item.category] = [];
    }
    acc[item.category].push(item);
    return acc;
  }, {} as Record<string, MenuItem[]>);

  return (
    <div className="max-w-4xl mx-auto bg-white p-6 rounded-lg shadow-md">
      <div className="flex justify-between items-center mb-6">
        <h2 className="text-2xl font-bold text-gray-800">Menu Items</h2>
        <button
          onClick={onAddItem}
          className="bg-blue-500 text-white py-2 px-4 rounded-md hover:bg-blue-600 focus:outline-none focus:ring-2 focus:ring-blue-500 flex items-center"
        >
          <Plus className="w-4 h-4 mr-2" />
          Add Item
        </button>
      </div>

      {isLoading ? (
        <div className="text-center py-8">
          <div className="inline-block animate-spin rounded-full h-8 w-8 border-b-2 border-blue-500"></div>
          <p className="mt-2 text-gray-600">Loading menu items...</p>
        </div>
      ) : Object.keys(groupedItems).length === 0 ? (
        <div className="text-center py-8">
          <p className="text-gray-600 mb-4">No menu items yet. Add your first item!</p>
          <button
            onClick={onAddItem}
            className="bg-blue-500 text-white py-2 px-4 rounded-md hover:bg-blue-600 focus:outline-none focus:ring-2 focus:ring-blue-500"
          >
            Add Menu Item
          </button>
        </div>
      ) : (
        <div className="space-y-6">
          {Object.entries(groupedItems).map(([category, items]) => (
            <div key={category}>
              <h3 className="text-xl font-semibold text-gray-800 mb-3 border-b border-gray-200 pb-2">
                {category}
              </h3>
              <div className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
                {items.map((item) => (
                  <div key={item.id} className="border border-gray-200 rounded-lg p-4 hover:shadow-md transition-shadow">
                    {item.imageUrl && (
                      <img 
                        src={item.imageUrl} 
                        alt={item.name}
                        className="w-full h-32 object-cover rounded-md mb-3"
                        onError={(e) => {
                          e.currentTarget.style.display = 'none';
                        }}
                      />
                    )}
                    <div className="flex justify-between items-start mb-2">
                      <h4 className="font-semibold text-gray-800">{item.name}</h4>
                      <span className="text-green-600 font-bold">${item.price.toFixed(2)}</span>
                    </div>
                    {item.description && (
                      <p className="text-gray-600 text-sm mb-3">{item.description}</p>
                    )}
                    <div className="flex justify-between items-center">
                      <span className={`px-2 py-1 rounded-full text-xs ${
                        item.available 
                          ? 'bg-green-100 text-green-800' 
                          : 'bg-red-100 text-red-800'
                      }`}>
                        {item.available ? 'Available' : 'Unavailable'}
                      </span>
                      <div className="flex space-x-2">
                        <button
                          onClick={() => onEditItem(item)}
                          className="text-blue-500 hover:text-blue-700 p-1"
                        >
                          <Edit className="w-4 h-4" />
                        </button>
                        <button
                          onClick={() => onDeleteItem(item.id)}
                          className="text-red-500 hover:text-red-700 p-1"
                        >
                          <Trash2 className="w-4 h-4" />
                        </button>
                      </div>
                    </div>
                  </div>
                ))}
              </div>
            </div>
          ))}
        </div>
      )}
    </div>
  );
};

export default MenuDisplay;