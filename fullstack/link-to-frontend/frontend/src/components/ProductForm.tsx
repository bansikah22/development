import React, { useState } from 'react';
import Box from '@mui/material/Box';
import TextField from '@mui/material/TextField';
import Button from '@mui/material/Button';
import Typography from '@mui/material/Typography';

interface ProductFormProps {
  initialData?: {
    name: string;
    description: string;
    price: number;
    image?: File | null;
  };
  onSubmit: (data: { name: string; description: string; price: number; image?: File | null }) => void;
  submitText?: string;
}

const ProductForm: React.FC<ProductFormProps> = ({ initialData, onSubmit, submitText = 'Submit' }) => {
  const [name, setName] = useState(initialData?.name || '');
  const [description, setDescription] = useState(initialData?.description || '');
  const [price, setPrice] = useState(initialData?.price || 0);
  const [image, setImage] = useState<File | null>(initialData?.image || null);

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    onSubmit({ name, description, price, image });
  };

  return (
    <Box component="form" onSubmit={handleSubmit} sx={{ display: 'flex', flexDirection: 'column', gap: 2, maxWidth: 400, bgcolor: '#fafafa', p: 3, borderRadius: 2, boxShadow: 2 }}>
      <Typography variant="h6" sx={{ mb: 1 }}>{submitText} Product</Typography>
      <TextField
        label="Product Name"
        placeholder="e.g. Apple iPhone 15"
        value={name}
        onChange={e => setName(e.target.value)}
        required
        fullWidth
      />
      <TextField
        label="Description"
        placeholder="e.g. Latest model with advanced features"
        value={description}
        onChange={e => setDescription(e.target.value)}
        required
        multiline
        minRows={2}
        fullWidth
      />
      <TextField
        label="Price (USD)"
        placeholder="e.g. 999.99"
        type="text"
        value={price === 0 ? '' : price}
        onChange={e => {
          const val = e.target.value;
          if (/^\d*\.?\d*$/.test(val)) {
            setPrice(val === '' ? 0 : Number(val));
          }
        }}
        required
        fullWidth
      />
      <Button
        variant="contained"
        component="label"
        sx={{ alignSelf: 'flex-start', mt: 1 }}
      >
        {image ? 'Change Image' : 'Upload Image'}
        <input
          type="file"
          accept="image/*"
          hidden
          onChange={e => setImage(e.target.files ? e.target.files[0] : null)}
        />
      </Button>
      {image && <Typography variant="body2" sx={{ mt: 1 }}>Selected: {image.name}</Typography>}
      <Button type="submit" variant="contained" color="primary" sx={{ mt: 2 }}>{submitText}</Button>
    </Box>
  );
};

export default ProductForm; 