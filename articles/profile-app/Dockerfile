# Stage 1: Build stage
FROM node:18-alpine AS build
WORKDIR /app
COPY package.json package-lock.json ./
RUN npm ci --production
COPY app.js ./

# Stage 2: Production stage
FROM node:18-slim
WORKDIR /app
RUN apt-get update && apt-get install -y curl && rm -rf /var/lib/apt/lists/*
COPY --from=build /app/node_modules /app/node_modules
COPY --from=build /app/app.js /app/app.js
CMD ["node", "app.js"]
EXPOSE 3001