FROM node:18-alpine
WORKDIR /app
COPY app.js package.json ./
RUN npm install express
CMD ["node", "app.js"]
EXPOSE 3001
