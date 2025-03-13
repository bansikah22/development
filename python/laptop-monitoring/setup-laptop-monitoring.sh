#!/bin/bash

# Create project directory and subdirectories
mkdir -p laptop-monitor/app/templates laptop-monitor/static/css laptop-monitor/static/js laptop-monitor/tests

# Navigate to project directory
cd laptop-monitor

# Create Dockerfile with a debug command to list files
cat <<EOF > Dockerfile
FROM python:3.9-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install -r requirements.txt
COPY . .
# Debug: List files in /app to verify static files
RUN ls -la /app && ls -la /app/static && ls -la /app/static/css && ls -la /app/static/js
CMD ["python", "app/__init__.py"]
EOF

# Create docker-compose.yml
cat <<EOF > docker-compose.yml
services:
  flask-app:
    build: .
    ports:
      - "5001:5000"
    depends_on:
      - redis
    environment:
      - REDIS_HOST=redis
  redis:
    image: redis:latest
    ports:
      - "6379:6379"
    volumes:
      - redis-data:/data

volumes:
  redis-data:
EOF

# Create requirements.txt
cat <<EOF > requirements.txt
flask==2.3.3
redis==5.0.1
psutil==5.9.5
EOF

# Create app/__init__.py
cat <<EOF > app/__init__.py
import sys
import os
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from flask import Flask
from routes import init_routes

app = Flask(__name__)

init_routes(app)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
EOF

# Create app/routes.py
cat <<EOF > app/routes.py
from flask import render_template
from monitor import get_metrics
from redis_client import store_metrics, get_metrics_history

def init_routes(app):
    @app.route('/')
    def dashboard():
        metrics = get_metrics()
        store_metrics(metrics)
        history = get_metrics_history()
        return render_template('index.html', metrics=metrics, history=history)

    @app.route('/api/metrics')
    def api_metrics():
        return get_metrics()
EOF

# Create app/monitor.py
cat <<EOF > app/monitor.py
import psutil
import time

def get_metrics():
    return {
        "cpu_percent": psutil.cpu_percent(interval=1),
        "memory_percent": psutil.virtual_memory().percent,
        "disk_percent": psutil.disk_usage('/').percent,
        "timestamp": int(time.time())
    }
EOF

# Create app/redis_client.py
cat <<EOF > app/redis_client.py
import redis
import json

redis_client = redis.Redis(host='redis', port=6379, decode_responses=True)

def store_metrics(metrics):
    redis_client.lpush("metrics", json.dumps(metrics))
    redis_client.ltrim("metrics", 0, 99)  # Keep only 100 recent entries

def get_metrics_history():
    return [json.loads(entry) for entry in redis_client.lrange("metrics", 0, -1)]
EOF

# Create app/templates/index.html
cat <<EOF > app/templates/index.html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Laptop Monitor</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <link rel="stylesheet" href="{{ url_for('static', filename='css/style.css') }}">
</head>
<body>
    <div class="container">
        <h1>Laptop Performance Dashboard</h1>
        <div class="metrics-grid">
            <div class="metric-card">
                <h3>CPU Usage</h3>
                <p class="metric-value">{{ metrics.cpu_percent }}%</p>
            </div>
            <div class="metric-card">
                <h3>Memory Usage</h3>
                <p class="metric-value">{{ metrics.memory_percent }}%</p>
            </div>
            <div class="metric-card">
                <h3>Disk Usage</h3>
                <p class="metric-value">{{ metrics.disk_percent }}%</p>
            </div>
        </div>
        <div class="chart-container">
            <canvas id="performanceChart"></canvas>
        </div>
    </div>
    <script src="{{ url_for('static', filename='js/script.js') }}"></script>
</body>
</html>
EOF

# Create static/css/style.css
cat <<EOF > static/css/style.css
body {
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    background-color: #f4f7fa;
    margin: 0;
    padding: 0;
    color: #333;
}

.container {
    max-width: 1200px;
    margin: 40px auto;
    padding: 20px;
}

h1 {
    text-align: center;
    color: #2c3e50;
    margin-bottom: 30px;
    font-size: 2.5em;
}

.metrics-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
    gap: 20px;
    margin-bottom: 40px;
}

.metric-card {
    background: #ffffff;
    border-radius: 10px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    padding: 20px;
    text-align: center;
    transition: transform 0.2s;
}

.metric-card:hover {
    transform: translateY(-5px);
}

.metric-card h3 {
    margin: 0 0 10px;
    color: #34495e;
    font-size: 1.2em;
}

.metric-value {
    font-size: 2em;
    font-weight: bold;
    color: #2980b9;
    margin: 0;
}

.chart-container {
    background: #ffffff;
    border-radius: 10px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    padding: 20px;
    max-width: 100%;
}

canvas {
    width: 100% !important;
    height: auto !important;
}
EOF

# Create static/js/script.js
cat <<EOF > static/js/script.js
function updateChart() {
    fetch('/api/metrics')
        .then(response => response.json())
        .then(data => {
            const time = new Date().toLocaleTimeString();
            performanceChart.data.labels.push(time);
            
            performanceChart.data.datasets[0].data.push(data.cpu_percent);
            performanceChart.data.datasets[1].data.push(data.memory_percent);
            performanceChart.data.datasets[2].data.push(data.disk_percent);

            if (performanceChart.data.labels.length > 20) {
                performanceChart.data.labels.shift();
                performanceChart.data.datasets.forEach(dataset => dataset.data.shift());
            }
            performanceChart.update();
        });
}

const ctx = document.getElementById('performanceChart').getContext('2d');
const performanceChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [],
        datasets: [
            {
                label: 'CPU Usage (%)',
                data: [],
                borderColor: '#2980b9',
                backgroundColor: 'rgba(41, 128, 185, 0.1)',
                fill: true
            },
            {
                label: 'Memory Usage (%)',
                data: [],
                borderColor: '#27ae60',
                backgroundColor: 'rgba(39, 174, 96, 0.1)',
                fill: true
            },
            {
                label: 'Disk Usage (%)',
                data: [],
                borderColor: '#e74c3c',
                backgroundColor: 'rgba(231, 76, 60, 0.1)',
                fill: true
            }
        ]
    },
    options: {
        responsive: true,
        scales: {
            y: {
                beginAtZero: true,
                max: 100,
                title: {
                    display: true,
                    text: 'Percentage (%)'
                }
            },
            x: {
                title: {
                    display: true,
                    text: 'Time'
                }
            }
        },
        plugins: {
            legend: {
                position: 'top'
            }
        }
    }
});

setInterval(updateChart, 5000); // Update every 5 seconds
EOF

# Create tests/test_monitor.py
cat <<EOF > tests/test_monitor.py
import unittest
from app.monitor import get_metrics

class TestMonitor(unittest.TestCase):
    def test_get_metrics(self):
        metrics = get_metrics()
        self.assertIn("cpu_percent", metrics)
        self.assertIn("memory_percent", metrics)

if __name__ == "__main__":
    unittest.main()
EOF

# Create README.md
cat <<EOF > README.md
# Laptop Monitor
A Flask app to monitor laptop performance using Redis.

## Setup
1. Install Docker and Docker Compose.
2. Run: \`docker-compose up --build\`
3. Visit: \`http://localhost:5001\`

## Requirements
- Python 3.9
- Docker

## Features
- Real-time CPU, memory, and disk usage
- Historical data visualization with charts
EOF

# Set executable permissions for the script itself
chmod +x ../setup_laptop_monitor.sh

echo "Project structure created successfully! Run 'cd laptop-monitor && docker-compose up --build' to start the app."