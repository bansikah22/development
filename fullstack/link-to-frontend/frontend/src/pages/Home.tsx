import React, { useEffect, useState } from 'react';
import Grid from '@mui/material/Grid';
import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import Typography from '@mui/material/Typography';
import CardActions from '@mui/material/CardActions';
import Box from '@mui/material/Box';
import Button from '@mui/material/Button';
import { fetchProducts } from '../services/api';

interface Product {
  id: number;
  name: string;
  description: string;
  price: number;
}

const Home: React.FC<{ searchQuery: string; onAddToCart: (product: any) => void }> = ({ searchQuery, onAddToCart }) => {
  const [products, setProducts] = useState<Product[]>([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    fetchProducts()
      .then(setProducts)
      .catch(console.error)
      .finally(() => setLoading(false));
  }, []);

  const filtered = products.filter(p =>
    p.name.toLowerCase().includes(searchQuery.toLowerCase()) ||
    p.description.toLowerCase().includes(searchQuery.toLowerCase())
  );

  if (loading) return <Box sx={{ p: 4 }}>Loading...</Box>;

  return (
    <Box sx={{ p: 4 }}>
      <Typography variant="h4" gutterBottom>All Products</Typography>
      <Grid container spacing={3} component="div">
        {filtered.map(product => (
          <Grid {...({ item: true, xs: 12, sm: 6, md: 4, lg: 3, key: product.id })}>
            <Card sx={{ minHeight: 200, display: 'flex', flexDirection: 'column', justifyContent: 'space-between' }}>
              <CardContent>
                {Boolean((product as any).image) && (
                  <img
                    src={`${process.env.REACT_APP_BACKEND_URL || 'http://localhost:8082/api/products'}/${product.id}/image`}
                    alt={product.name}
                    style={{ width: '100%', maxHeight: 180, objectFit: 'cover', marginBottom: 8 }}
                  />
                )}
                <Typography variant="h6">{product.name}</Typography>
                <Typography variant="body2" color="text.secondary">{product.description}</Typography>
                <Typography variant="subtitle1" sx={{ mt: 1, fontWeight: 'bold' }}>${product.price.toFixed(2)}</Typography>
              </CardContent>
              <CardActions>
                <Button variant="contained" color="primary" onClick={() => onAddToCart(product)}>
                  Add to Cart
                </Button>
              </CardActions>
            </Card>
          </Grid>
        ))}
      </Grid>
      {filtered.length === 0 && <Typography sx={{ mt: 4 }}>No products found.</Typography>}
    </Box>
  );
};

export default Home; 