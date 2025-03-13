FROM python:3.9-slim
WORKDIR /app
COPY requirements.txt /app/
COPY static/ /app/static/
COPY app/ /app/app/
RUN pip install -r requirements.txt

# Debug: List files in /app to verify static files
RUN ls -la /app && ls -la /app/static && ls -la /app/static/css && ls -la /app/static/js
CMD ["python", "app/__init__.py"]
