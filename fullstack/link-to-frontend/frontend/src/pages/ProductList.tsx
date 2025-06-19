import React, { useEffect, useState } from 'react';
import Grid from '@mui/material/Grid';
import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import Typography from '@mui/material/Typography';
import CardActions from '@mui/material/CardActions';
import Button from '@mui/material/Button';
import Box from '@mui/material/Box';
import IconButton from '@mui/material/IconButton';
import EditIcon from '@mui/icons-material/Edit';
import DeleteIcon from '@mui/icons-material/Delete';
import { fetchProducts, createProduct, updateProduct, deleteProduct } from '../services/api';
import ProductForm from '../components/ProductForm';

interface Product {
  id: number;
  name: string;
  description: string;
  price: number;
}

const ProductList: React.FC = () => {
  const [products, setProducts] = useState<Product[]>([]);
  const [showForm, setShowForm] = useState(false);
  const [editProduct, setEditProduct] = useState<Product | null>(null);

  const loadProducts = () => {
    fetchProducts()
      .then(setProducts)
      .catch(console.error);
  };

  useEffect(() => {
    loadProducts();
  }, []);

  const handleCreate = async (data: any) => {
    await createProduct(data);
    setShowForm(false);
    loadProducts();
  };

  const handleEdit = (product: Product) => {
    setEditProduct(product);
    setShowForm(true);
  };

  const handleUpdate = async (data: any) => {
    if (editProduct) {
      await updateProduct(editProduct.id, data);
      setEditProduct(null);
      setShowForm(false);
      loadProducts();
    }
  };

  const handleDelete = async (id: number) => {
    if (window.confirm('Are you sure you want to delete this product?')) {
      await deleteProduct(id);
      loadProducts();
    }
  };

  return (
    <Box sx={{ p: 4 }}>
      <Typography variant="h4" gutterBottom>Manage Products</Typography>
      <Button variant="contained" color="primary" onClick={() => { setShowForm(true); setEditProduct(null); }} sx={{ mb: 2 }}>
        Add Product
      </Button>
      {showForm && (
        <Box sx={{ mb: 3 }}>
          <ProductForm
            initialData={editProduct || undefined}
            onSubmit={editProduct ? handleUpdate : handleCreate}
            submitText={editProduct ? 'Update' : 'Create'}
          />
          <Button onClick={() => { setShowForm(false); setEditProduct(null); }} sx={{ mt: 1 }}>Cancel</Button>
        </Box>
      )}
      <Grid container spacing={3}>
        {products.map((p) => (
          <Grid {...({ item: true, xs: 12, sm: 6, md: 4, lg: 3, key: p.id })}>
            <Card sx={{ minHeight: 200, display: 'flex', flexDirection: 'column', justifyContent: 'space-between', position: 'relative' }}>
              <CardContent>
                {Boolean((p as any).image) && (
                  <img
                    src={`${process.env.REACT_APP_BACKEND_URL || 'http://localhost:8082/api/products'}/${p.id}/image`}
                    alt={p.name}
                    style={{ width: '100%', maxHeight: 180, objectFit: 'cover', marginBottom: 8 }}
                  />
                )}
                <Typography variant="h6">{p.name}</Typography>
                <Typography variant="body2" color="text.secondary">{p.description}</Typography>
                <Typography variant="subtitle1" sx={{ mt: 1, fontWeight: 'bold' }}>${p.price.toFixed(2)}</Typography>
              </CardContent>
              <CardActions sx={{ justifyContent: 'flex-end' }}>
                <IconButton color="primary" onClick={() => handleEdit(p)}><EditIcon /></IconButton>
                <IconButton color="error" onClick={() => handleDelete(p.id)}><DeleteIcon /></IconButton>
              </CardActions>
            </Card>
          </Grid>
        ))}
      </Grid>
    </Box>
  );
};

export default ProductList; 