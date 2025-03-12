# Profile App

## Apply & Test in Kubernetes with Minikube

### 1️⃣ Start Minikube
```bash
minikube start
```

### 2️⃣ Deploy to Kubernetes
```bash
kubectl apply -k k8s/overlays/dev
kubectl apply -k k8s/overlays/prod
kubectl apply -k k8s/overlays/staging
```

### 3️⃣ Test the App
#### Port Forwarding
```bash
kubectl port-forward -n dev svc/profile-service 8080:80
kubectl port-forward -n staging svc/profile-service 8081:80
kubectl port-forward -n prod svc/profile-service 8082:80
```

#### Access the App
Open your browser and navigate to:
- Development: [http://localhost:8080](http://localhost:8080)
- Staging: [http://localhost:8081](http://localhost:8081)
- Production: [http://localhost:8082](http://localhost:8082)

### 4️⃣ Verify Deployments
```bash
kubectl get pods -n dev
kubectl get pods -n staging
kubectl get pods -n prod

kubectl get services -n dev
kubectl get services -n staging
kubectl get services -n prod
```

### 5️⃣ Check Logs to Confirm Colors
```bash
kubectl logs -n dev deployment/profile-app
kubectl logs -n staging deployment/profile-app
kubectl logs -n prod deployment/profile-app
```

### 6️⃣ Test Persistent Storage
#### Check the Volume Mount
```bash
kubectl exec -n dev -it $(kubectl get pod -n dev -l app=profile-app -o jsonpath='{.items[0].metadata.name}') -- ls /app/config
```

This modifies the config inside the pod.

#### Restart the Pod & Check if Config Persists
```bash
kubectl delete pod -n dev -l app=profile-app
kubectl get pods -n dev -w
```

### 7️⃣ Verify the Updated Config
```bash
kubectl exec -n dev -it $(kubectl get pod -n dev -l app=profile-app -o jsonpath='{.items[0].metadata.name}') -- curl profile-service
```

Open [http://localhost:8080](http://localhost:8080) in your browser to see the updated configuration! 🎉