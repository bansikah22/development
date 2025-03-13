import redis
import json

redis_client = redis.Redis(host='redis', port=6379, decode_responses=True)

def store_metrics(metrics):
    redis_client.lpush("metrics", json.dumps(metrics))
    redis_client.ltrim("metrics", 0, 99)  # Keep only 100 recent entries

def get_metrics_history():
    return [json.loads(entry) for entry in redis_client.lrange("metrics", 0, -1)]
