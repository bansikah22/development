# Link-to-Frontend & Product Backend

## How to Run the Application

### Backend (Spring Boot)
1. Open a terminal and navigate to the `Product` directory:
   ```bash
   cd Product
   ```
2. Run the backend server:
   ```bash
   ./mvnw spring-boot:run
   ```
   or on Windows:
   ```bash
   mvnw.cmd spring-boot:run
   ```
3. The backend will start on [http://localhost:8082](http://localhost:8082) by default.

### Frontend (React)
1. Open a new terminal and navigate to the `frontend` directory:
   ```bash
   cd frontend
   ```
2. Install dependencies (if you haven't already):
   ```bash
   npm install
   ```
3. Start the frontend development server:
   ```bash
   npm start
   ```
4. The frontend will be available at [http://localhost:3000](http://localhost:3000).

YOu should see 
![Home Page](./Screenshot%202025-06-19%20at%201.57.45 PM%20copy.png)

### Notes
- Ensure the backend is running before using the frontend for full functionality.
- You can configure the backend URL for the frontend in `frontend/.env` using the `REACT_APP_BACKEND_URL` variable.

---

