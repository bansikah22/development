import redis
import time

r = redis.StrictRedis(host='localhost', port=6379, db=0)

r.mset({'France': 'Paris', 'UK': 'London'})

# if (r.exists("Serbia")):
#     print(r.get("Serbia"))
# else:
#     print("Cannot find the capital, Getting from API")

r.psetex("Serbia", 10000, "Belgrade")
print(r.get("Serbia"))

time.sleep(2)
print(r.get("Serbia"))


