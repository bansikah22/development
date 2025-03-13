FROM python:3.9-slim
WORKDIR /app

# Copy requirements first to leverage Docker cache
COPY requirements.txt /app/
RUN pip install -r requirements.txt

# Create static directory structure explicitly
RUN mkdir -p /app/static/css /app/static/js

# Copy all application files
COPY . /app/

# Ensure proper permissions for static files
RUN chmod -R 755 /app/static

CMD ["python", "-m", "flask", "run", "--host=0.0.0.0"]
