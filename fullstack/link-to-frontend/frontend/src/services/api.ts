const BASE_URL = process.env.REACT_APP_BACKEND_URL || 'http://localhost:8082/api/products';

export async function fetchProducts() {
  const response = await fetch(`${BASE_URL}`);
  if (!response.ok) throw new Error('Failed to fetch products');
  return response.json();
}

export async function createProduct(data: { name: string; description: string; price: number; image?: File }) {
  const formData = new FormData();
  formData.append('name', data.name);
  formData.append('description', data.description);
  formData.append('price', String(data.price));
  if (data.image) formData.append('image', data.image);

  const response = await fetch(`${BASE_URL}`, {
    method: 'POST',
    body: formData,
  });
  if (!response.ok) throw new Error('Failed to create product');
  return response.json();
}

export async function updateProduct(id: number, data: { name: string; description: string; price: number; image?: File }) {
  const formData = new FormData();
  formData.append('name', data.name);
  formData.append('description', data.description);
  formData.append('price', String(data.price));
  if (data.image) formData.append('image', data.image);

  const response = await fetch(`${BASE_URL}/${id}`, {
    method: 'PUT',
    body: formData,
  });
  if (!response.ok) throw new Error('Failed to update product');
  return response.json();
}

export async function deleteProduct(id: number) {
  const response = await fetch(`${BASE_URL}/${id}`, {
    method: 'DELETE',
  });
  if (!response.ok) throw new Error('Failed to delete product');
} 