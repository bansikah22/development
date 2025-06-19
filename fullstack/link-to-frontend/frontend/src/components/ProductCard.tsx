import React from 'react';

interface ProductCardProps {
  name: string;
  description?: string;
  price?: number;
}

const ProductCard: React.FC<ProductCardProps> = ({ name, description, price }) => {
  return (
    <div style={{
      border: '1px solid #e0e0e0',
      borderRadius: 8,
      padding: 16,
      margin: 8,
      boxShadow: '0 2px 8px rgba(0,0,0,0.05)',
      background: '#fff',
      minWidth: 250
    }}>
      <h2 style={{ margin: '0 0 8px 0' }}>{name}</h2>
      {description && <p style={{ color: '#666' }}>{description}</p>}
      {price !== undefined && <p style={{ fontWeight: 'bold' }}>${price.toFixed(2)}</p>}
    </div>
  );
};

export default ProductCard; 