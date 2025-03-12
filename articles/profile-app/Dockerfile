# Stage 1: Build stage
FROM node:18-alpine AS build
WORKDIR /app
COPY package.json ./
RUN npm install

# Stage 2: Production stage
FROM node:18-alpine
WORKDIR /app
COPY --from=build /app/node_modules /app/node_modules
COPY app.js ./
CMD ["node", "app.js"]
EXPOSE 3001