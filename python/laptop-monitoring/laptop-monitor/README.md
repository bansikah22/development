# Laptop Monitor
A Flask app to monitor laptop performance using Redis.

## Setup
1. Install Docker and Docker Compose.
2. Run: `docker-compose up --build`
3. Visit: `http://localhost:5001`

## Requirements
- Python 3.9
- Docker

## Debug

docker-compose exec flask-app ls -la /app/static/css


## Features
- Real-time CPU, memory, and disk usage
- Historical data visualization with charts
