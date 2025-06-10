# 📦 Java Generics Real-World Example

This example demonstrates how to use **Generics in Java** with a simple `DataStorage<T>` class that can store any type of object, such as `User` or `Product`.

---

## ✅ Use Case: Generic DataStorage Class

We want to create a reusable storage class that can hold any type of object, making our code flexible, reusable, and type-safe.

---

## 💡 Implementation

### Generic DataStorage Class

```java
// Generic storage class
public class DataStorage<T> {
    private T data;

    public void setData(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }
}
```

---

### User Class

```java
public class User {
    private String name;
    private int age;

    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void printUserInfo() {
        System.out.println("User: " + name + ", Age: " + age);
    }
}
```

---

### Product Class

```java
public class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public void printProductInfo() {
        System.out.println("Product: " + name + ", Price: $" + price);
    }
}
```

---

### Main Class

```java
public class Main {
    public static void main(String[] args) {
        // Store User
        DataStorage<User> userStorage = new DataStorage<>();
        User user = new User("Alice", 30);
        userStorage.setData(user);
        userStorage.getData().printUserInfo();

        // Store Product
        DataStorage<Product> productStorage = new DataStorage<>();
        Product product = new Product("Laptop", 1200.50);
        productStorage.setData(product);
        productStorage.getData().printProductInfo();
    }
}
```

---

### ✅ Output

```
User: Alice, Age: 30
Product: Laptop, Price: $1200.5
```

---

## 📘 Little Notes About Generics in Java

### 🔁 Why Use Generics?

- **Code Reusability**: Write once, use for any type.
- **Type Safety**: Compile-time checking, no need for casting.
- **Cleaner Code**: No need for multiple overloaded versions.

---

### 🔍 Type Erasure

- Java uses **type erasure** to remove generic type information at runtime.
- So `DataStorage<User>` and `DataStorage<Product>` are the same at runtime.

---

### 🔒 Generic Types Can Be Restricted (Bounded Types)

You can limit what type `T` can be:

```java
public class ZooCage<T extends Animal> {
    private T animal;
}
```

In this case, `T` must be a subclass of `Animal`.

---

### 🎯 Wildcards (`?`)

- Useful in method parameters when the type is unknown.
- Examples:
    - `List<?>`: List of unknown type.
    - `List<? extends Number>`: List of any type that is a subclass of `Number`.

---

## ✅ Summary

This example shows how Java Generics:

- Help build **reusable** and **type-safe** code.
- Allow different types (`User`, `Product`) to be handled using the same logic.
- **Reduce duplication** and make your code cleaner and easier to maintain.

---
