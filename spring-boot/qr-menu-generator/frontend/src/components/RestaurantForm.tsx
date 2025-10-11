import React from 'react';
import { useForm } from 'react-hook-form';
import type { RestaurantRequest } from '../types';

interface RestaurantFormProps {
  onSubmit: (data: RestaurantRequest) => void;
  initialData?: RestaurantRequest;
  isLoading?: boolean;
}

const RestaurantForm: React.FC<RestaurantFormProps> = ({ 
  onSubmit, 
  initialData, 
  isLoading = false 
}) => {
  const { register, handleSubmit, formState: { errors } } = useForm<RestaurantRequest>({
    defaultValues: initialData
  });

  return (
    <div className="bg-white/90 backdrop-blur-sm rounded-2xl shadow-2xl p-8 border border-white/20">
      <div className="flex items-center mb-6 justify-center">
        <div className="h-8 w-8 bg-gradient-to-br from-orange-400 to-rose-500 rounded-lg flex items-center justify-center mr-3 shadow-lg">
          <svg className="h-4 w-4 text-white" fill="currentColor" viewBox="0 0 20 20">
            <path fillRule="evenodd" d="M4 4a2 2 0 012-2h8a2 2 0 012 2v12a1 1 0 110 2h-3a1 1 0 01-1-1v-6a1 1 0 00-1-1H9a1 1 0 00-1 1v6a1 1 0 01-1 1H4a1 1 0 110-2V4zm3 1h2v2H7V5zm2 4H7v2h2V9zm2-4h2v2h-2V5zm2 4h-2v2h2V9z" clipRule="evenodd" />
          </svg>
        </div>
        <h2 className="text-2xl font-bold text-orange-800">Restaurant Information</h2>
      </div>
      
      <form onSubmit={handleSubmit(onSubmit)} className="space-y-6">
        <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Restaurant Name *
            </label>
            <input
              {...register('name', { required: 'Restaurant name is required' })}
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="Enter restaurant name"
            />
            {errors.name && (
              <p className="text-red-500 text-sm mt-1">{errors.name.message}</p>
            )}
          </div>

          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Phone
            </label>
            <input
              {...register('phone')}
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="Contact phone number"
            />
          </div>
        </div>

        <div className="space-y-2">
          <label className="text-sm font-medium text-orange-700">
            Description
          </label>
          <textarea
            {...register('description')}
            className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300 resize-none"
            placeholder="Brief description of your restaurant"
            rows={3}
          />
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Address
            </label>
            <input
              {...register('address')}
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="Restaurant address"
            />
          </div>

          <div className="space-y-2">
            <label className="text-sm font-medium text-orange-700">
              Email
            </label>
            <input
              {...register('email')}
              type="email"
              className="w-full px-4 py-3 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
              placeholder="Contact email"
            />
          </div>
        </div>

        <div className="space-y-2">
          <label className="text-sm font-medium text-orange-700">
            Theme Color
          </label>
          <input
            {...register('themeColor')}
            type="color"
            className="w-full h-12 bg-orange-50/50 border border-orange-200 rounded-xl focus:outline-none focus:ring-3 focus:ring-orange-500/20 focus:border-orange-500 transition-all duration-300"
            defaultValue="#ea580c"
          />
        </div>

        <button
          type="submit"
          disabled={isLoading}
          className="w-full bg-gradient-to-r from-orange-500 to-rose-500 hover:from-orange-600 hover:to-rose-600 text-white font-semibold py-4 px-8 rounded-xl transition-all duration-300 transform hover:scale-105 hover:shadow-lg disabled:opacity-50 disabled:cursor-not-allowed disabled:transform-none"
        >
          {isLoading ? (
            <div className="flex items-center justify-center">
              <div className="animate-spin rounded-full h-5 w-5 border-b-2 border-white mr-2"></div>
              Saving Restaurant...
            </div>
          ) : (
            'Save Restaurant'
          )}
        </button>
      </form>
    </div>
  );
};

export default RestaurantForm;