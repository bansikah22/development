import React, { useState } from 'react';
import { BrowserRouter as Router, Routes, Route, Link, useNavigate } from 'react-router-dom';
import { AppBar, Toolbar, Typography, Button, Box, InputBase, Badge, IconButton } from '@mui/material';
import SearchIcon from '@mui/icons-material/Search';
import ShoppingCartIcon from '@mui/icons-material/ShoppingCart';
import Home from './pages/Home';
import ProductList from './pages/ProductList';

const Navbar: React.FC<{ onSearch: (q: string) => void; cartCount: number }> = ({ onSearch, cartCount }) => {
  const [search, setSearch] = useState('');
  const navigate = useNavigate();

  const handleSearch = (e: React.FormEvent) => {
    e.preventDefault();
    onSearch(search);
    navigate('/');
  };

  return (
    <AppBar position="sticky">
      <Toolbar>
        <Typography variant="h6" component="div" sx={{ flexGrow: 1 }}>
          <Button color="inherit" component={Link} to="/">Home</Button>
          <Button color="inherit" component={Link} to="/products">Products</Button>
        </Typography>
        <Box component="form" onSubmit={handleSearch} sx={{ display: 'flex', alignItems: 'center', bgcolor: 'rgba(255,255,255,0.15)', borderRadius: 1, pl: 1, mr: 2 }}>
          <InputBase
            placeholder="Search…"
            value={search}
            onChange={e => setSearch(e.target.value)}
            sx={{ color: 'inherit', ml: 1 }}
            inputProps={{ 'aria-label': 'search' }}
          />
          <Button type="submit" color="inherit"><SearchIcon /></Button>
        </Box>
        <IconButton color="inherit" component={Link} to="/cart">
          <Badge badgeContent={cartCount} color="secondary">
            <ShoppingCartIcon />
          </Badge>
        </IconButton>
      </Toolbar>
    </AppBar>
  );
};

const App: React.FC = () => {
  const [searchQuery, setSearchQuery] = useState('');
  const [cart, setCart] = useState<any[]>([]);

  const handleAddToCart = (product: any) => {
    setCart(prev => [...prev, product]);
  };

  return (
    <Router>
      <Navbar onSearch={setSearchQuery} cartCount={cart.length} />
      <Box sx={{ minHeight: '90vh' }}>
        <Routes>
          <Route path="/" element={<Home searchQuery={searchQuery} onAddToCart={handleAddToCart} />} />
          <Route path="/products" element={<ProductList />} />
          {/* You can add a Cart page here if needed */}
        </Routes>
      </Box>
      <Box component="footer" sx={{ textAlign: 'center', py: 2, color: 'white', bgcolor: 'primary.main' }}>
        © iinsys 2025
      </Box>
    </Router>
  );
};

export default App;
