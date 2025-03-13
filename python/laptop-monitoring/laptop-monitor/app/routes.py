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
