## Apply & Test in Kubernetes
1️⃣ Build & Push Docker Image
```bash
docker build -t profile-app .
docker tag profile-app YOUR_DOCKER_HUB_USERNAME/profile-app:latest
docker push YOUR_DOCKER_HUB_USERNAME/profile-app:latest
```
2️⃣ Deploy to Kubernetes
```bash
kubectl apply -f k8s/configmap.yaml
kubectl apply -f k8s/deployment.yaml
kubectl apply -f k8s/pvc.yaml
kubectl apply -f k8s/namespaces.yaml

```
3️⃣ Test the App
```bash
kubectl port-forward svc/profile-service 8080:80
kubectl port-forward -n dev svc/profile-service 8080:80
kubectl port-forward -n test svc/profile-service 8081:80
kubectl port-forward -n prod svc/profile-service 8082:80

```
📌 How to Test Persistent Storage
1️⃣ Check the Volume Mount
```bash
kubectl exec -it $(kubectl get pod -l app=profile -o jsonpath="{.items[0].metadata.name}") -- ls /app/config
```
2️⃣ Modify the Config File
```bash
kubectl exec -it $(kubectl get pod -l app=profile -o jsonpath="{.items[0].metadata.name}") -- sh -c "echo '{\"name\": \"Updated Name\", \"role\": \"Updated Role\", \"color\": \"red\"}' > /app/config/config.json"
```
This modifies the config inside the pod.
3️⃣ Restart the Pod & Check if Config Persists
```bash
kubectl delete pod -l app=profile
kubectl get pods -w
```
### verify deployments
```bash
kubectl get pods -n dev
kubectl get pods -n test
kubectl get pods -n prod

kubectl get services -n dev
kubectl get services -n test
kubectl get services -n prod


## Check Logs to Confirm Colors
kubectl logs -n dev deployment/profile-app
kubectl logs -n test deployment/profile-app
kubectl logs -n prod deployment/profile-app


kubectl exec -n dev -it $(kubectl get pod -n dev -l app=profile -o jsonpath='{.items[0].metadata.name}') -- curl profile-service
kubectl exec -n test -it $(kubectl get pod -n test -l app=profile -o jsonpath='{.items[0].metadata.name}') -- curl profile-service

kubectl exec -n prod -it $(kubectl get pod -n prod -l app=profile -o jsonpath='{.items[0].metadata.name}') -- curl profile-service

```
Open http://localhost:8080 in your browser! 🎉