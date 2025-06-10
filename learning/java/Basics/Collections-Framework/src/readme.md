# 📚 Java Collections Framework – List, Set, Map, Queue & More

The Java Collections Framework provides powerful **data structures** and **algorithms** to manage and manipulate groups of objects efficiently.

---

## 🧠 Why Collections Matter

- Store, retrieve, and manipulate **groups of data**
- Provide reusable **implementations of common data structures**
- Enable **sorting, searching, and iteration**

---

## 🧰 Core Interfaces

| Interface | Purpose                             | Implementations                     |
|----------|-------------------------------------|-------------------------------------|
| `List`   | Ordered, allows duplicates          | `ArrayList`, `LinkedList`           |
| `Set`    | No duplicates                        | `HashSet`, `LinkedHashSet`, `TreeSet`|
| `Map`    | Key-value pairs                      | `HashMap`, `TreeMap`, `LinkedHashMap`|
| `Queue`  | FIFO ordering                        | `LinkedList`, `PriorityQueue`       |
| `Deque`  | Double-ended queue                   | `ArrayDeque`, `LinkedList`          |

---

## 🏗️ Real-World Scenario: Inventory Management

We'll simulate a product inventory system that:

- Uses a `List` for products
- Uses a `Set` to ensure unique categories
- Uses a `Map` to look up prices
- Uses a `Queue` to process restocking requests

---

### ✅ 1. Product Model

```java
public class Product {
    private String name;
    private String category;

    public Product(String name, String category) {
        this.name = name;
        this.category = category;
    }

    public String getName() { return name; }
    public String getCategory() { return category; }

    @Override
    public String toString() {
        return name + " (" + category + ")";
    }
}
```

---

### ✅ 2. Main Inventory System

```java
import java.util.*;

public class InventorySystem {
    public static void main(String[] args) {
        // List of products
        List<Product> products = new ArrayList<>();
        products.add(new Product("Laptop", "Electronics"));
        products.add(new Product("Chair", "Furniture"));
        products.add(new Product("Phone", "Electronics"));

        // Set to track unique categories
        Set<String> categories = new HashSet<>();
        for (Product p : products) {
            categories.add(p.getCategory());
        }

        // Map for product prices
        Map<String, Double> priceMap = new HashMap<>();
        priceMap.put("Laptop", 1200.0);
        priceMap.put("Chair", 150.0);
        priceMap.put("Phone", 800.0);

        // Queue for restocking requests
        Queue<String> restockQueue = new LinkedList<>();
        restockQueue.add("Laptop");
        restockQueue.add("Chair");

        // Output
        System.out.println("Products:");
        products.forEach(System.out::println);

        System.out.println("\nCategories:");
        categories.forEach(System.out::println);

        System.out.println("\nProduct Prices:");
        priceMap.forEach((k, v) -> System.out.println(k + ": $" + v));

        System.out.println("\nProcessing Restock Queue:");
        while (!restockQueue.isEmpty()) {
            String item = restockQueue.poll();
            System.out.println("Restocking " + item);
        }
    }
}
```

---

## 📘 Little Notes on Java Collections

### 🔹 `List`
- Maintains **order**
- Allows **duplicates**
- Use `ArrayList` for fast read, `LinkedList` for fast insert/delete

### 🔹 `Set`
- No duplicates allowed
- `HashSet` for fast access, `TreeSet` for sorted data

### 🔹 `Map`
- Key-value pairs
- Keys are **unique**
- `HashMap` for speed, `TreeMap` for sorted keys

### 🔹 `Queue`
- FIFO structure
- `LinkedList` or `PriorityQueue`
- Great for **task processing** and **scheduling**

---

## 🎯 Summary

This example demonstrates how the Java Collections Framework:

- Supports a wide range of **data structures**
- Handles real-world needs like **unique values**, **key-value lookup**, and **FIFO queues**
- Makes it easy to **process, sort, filter**, and **group data**

---

💡 Common Use Cases:

- `List`: Displaying data in UI, storing logs
- `Set`: Tags, filters, preventing duplicates
- `Map`: Caching, database rows, config data
- `Queue`: Job/task processing, messaging systems

Let me know if you'd like an example with:
- Sorting collections
- Using `Comparator`
- Advanced Map methods (like `computeIfAbsent`)
