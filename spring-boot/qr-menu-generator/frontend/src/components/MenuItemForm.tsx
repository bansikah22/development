import React from 'react';
import { useForm } from 'react-hook-form';
import type { MenuItemRequest } from '../types';

interface MenuItemFormProps {
  onSubmit: (data: MenuItemRequest) => void;
  initialData?: MenuItemRequest;
  isLoading?: boolean;
  onCancel?: () => void;
}

const MenuItemForm: React.FC<MenuItemFormProps> = ({ 
  onSubmit, 
  initialData, 
  isLoading = false,
  onCancel 
}) => {
  const { register, handleSubmit, formState: { errors } } = useForm<MenuItemRequest>({
    defaultValues: initialData || { available: true, displayOrder: 0 }
  });

  const categories = [
    'Appetizers', 'Main Course', 'Desserts', 'Beverages', 
    'Salads', 'Soups', 'Sides', 'Specials'
  ];

  return (
    <div className="bg-white/90 backdrop-blur-sm rounded-2xl shadow-2xl p-8 border border-white/20 max-w-2xl mx-auto">
      <div className="flex items-center mb-6 justify-center">
        <div className="h-8 w-8 bg-gradient-to-br from-orange-400 to-rose-500 rounded-lg flex items-center justify-center mr-3 shadow-lg">
          <svg className="h-4 w-4 text-white" fill="currentColor" viewBox="0 0 20 20">
            <path d="M3 4a1 1 0 011-1h12a1 1 0 011 1v2a1 1 0 01-1 1H4a1 1 0 01-1-1V4zM3 10a1 1 0 011-1h6a1 1 0 011 1v6a1 1 0 01-1 1H4a1 1 0 01-1-1v-6zM14 9a1 1 0 00-1 1v6a1 1 0 001 1h2a1 1 0 001-1v-6a1 1 0 00-1-1h-2z"/>
          </svg>
        </div>
        <h2 className="text-2xl font-bold text-orange-800">
          {initialData ? 'Edit Menu Item' : 'Add Menu Item'}
        </h2>
      </div>
      
            <form onSubmit={handleSubmit(onSubmit)} className="space-y-6">
        <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Item Name *
            </label>
            <input
              {...register('name', { required: 'Item name is required' })}
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="Enter item name"
            />
            {errors.name && (
              <p className="text-red-500 text-sm mt-1">{errors.name.message}</p>
            )}
          </div>

          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Price *
            </label>
            <input
              {...register('price', { required: 'Price is required', min: 0 })}
              type="number"
              step="0.01"
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="0.00"
            />
            {errors.price && (
              <p className="text-red-500 text-sm mt-1">{errors.price.message}</p>
            )}
          </div>
        </div>

        <div className="space-y-2">
          <label className="text-sm font-medium text-orange-700">
            Description
          </label>
          <textarea
            {...register('description')}
            className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300 resize-none"
            placeholder="Describe the dish"
            rows={3}
          />
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Category *
            </label>
            <select
              {...register('category', { required: 'Category is required' })}
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
            >
              <option value="">Select a category</option>
              {categories.map(category => (
                <option key={category} value={category}>{category}</option>
              ))}
            </select>
            {errors.category && (
              <p className="text-red-500 text-sm mt-1">{errors.category.message}</p>
            )}
          </div>

          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Display Order
            </label>
            <input
              {...register('displayOrder')}
              type="number"
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="0"
            />
          </div>
        </div>

        <div className="space-y-2">
          <label className="text-sm font-medium text-orange-700">
            Image URL
          </label>
          <input
            {...register('imageUrl')}
            className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
            placeholder="https://example.com/image.jpg"
          />
        </div>

        <div className="flex items-center space-x-3">
          <input
            {...register('available')}
            type="checkbox"
            className="w-4 h-4 text-orange-600 bg-orange-50 border-orange-300 rounded focus:ring-orange-500"
          />
          <label className="text-sm font-medium text-orange-700">
            Available for order
          </label>
        </div>

        <div className="flex gap-4">
          <button
            type="submit"
            disabled={isLoading}
            className="flex-1 bg-gradient-to-r from-orange-500 to-rose-500 hover:from-orange-600 hover:to-rose-600 text-white font-semibold py-4 px-8 rounded-xl transition-all duration-300 transform hover:scale-105 hover:shadow-lg disabled:opacity-50 disabled:cursor-not-allowed disabled:transform-none"
          >
            {isLoading ? (
              <div className="flex items-center justify-center">
                <div className="animate-spin rounded-full h-5 w-5 border-b-2 border-white mr-2"></div>
                Saving...
              </div>
            ) : (
              'Save Item'
            )}
          </button>
          {onCancel && (
            <button
              type="button"
              onClick={onCancel}
              className="flex-1 bg-gradient-to-r from-gray-500 to-gray-600 hover:from-gray-600 hover:to-gray-700 text-white font-semibold py-4 px-8 rounded-xl transition-all duration-300 transform hover:scale-105 hover:shadow-lg"
            >
              Cancel
            </button>
          )}
        </div>
      </form>
    </div>
  );
};

export default MenuItemForm;