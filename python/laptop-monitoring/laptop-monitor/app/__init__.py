import sys
import os
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from flask import Flask
from routes import init_routes

app = Flask(__name__,
           static_folder='../static',  # Point to the static folder relative to this file
           static_url_path='')  # This ensures static files are served from root

init_routes(app)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
