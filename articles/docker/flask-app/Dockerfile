# Use a lightweight Python base image
FROM python:3.14.3-slim

# Set the working directory in the container
WORKDIR /app

# Copy the application files
COPY app.py /app
COPY requirements.txt /app

# Install the Python dependencies
RUN pip install --no-cache-dir -r requirements.txt

# Expose the port the Flask app runs on
EXPOSE 5000

# Run the Flask application
ENTRYPOINT ["python", "app.py"]

