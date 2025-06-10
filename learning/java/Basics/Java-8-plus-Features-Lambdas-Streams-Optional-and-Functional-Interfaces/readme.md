# 🚀 Java 8+ Features – Lambdas, Streams, Optional & Functional Interfaces

Java 8 introduced powerful features that make code more **concise**, **functional**, and **parallel-friendly**. These features are now widely used in modern applications and frameworks.

---

## 🧠 Why Java 8 Features Matter

- **Less boilerplate** with lambdas and method references
- **Stream API** for data processing pipelines
- **Optional** to reduce `null` checks
- **Functional interfaces** for reusable behavior blocks (like passing logic)

---

## 📦 Real-World Scenario: User Filtering with Streams and Lambdas

We’ll create a `User` model and filter users by role using Streams and Lambda expressions.

---

### ✅ 1. User Model

```java
public class User {
    private String username;
    private String email;
    private String role;

    public User(String username, String email, String role) {
        this.username = username;
        this.email = email;
        this.role = role;
    }

    public String getUsername() { return username; }
    public String getEmail() { return email; }
    public String getRole() { return role; }

    @Override
    public String toString() {
        return username + " (" + role + ")";
    }
}
```

---

### ✅ 2. Filtering with Streams & Lambdas

```java
import java.util.*;
import java.util.stream.Collectors;

public class UserService {
    public static void main(String[] args) {
        List<User> users = List.of(
            new User("alice", "alice@example.com", "admin"),
            new User("bob", "bob@example.com", "user"),
            new User("carol", "carol@example.com", "admin"),
            new User("dave", "dave@example.com", "user")
        );

        // Filter only admins
        List<User> admins = users.stream()
                .filter(u -> "admin".equals(u.getRole()))
                .collect(Collectors.toList());

        System.out.println("Admins:");
        admins.forEach(System.out::println);
    }
}
```

---

## ✅ Optional Example – Null-safe Email Lookup

```java
import java.util.Optional;

public class EmailService {
    public static Optional<String> getEmailByUsername(String username) {
        if ("bob".equals(username)) {
            return Optional.of("bob@example.com");
        } else {
            return Optional.empty(); // user not found
        }
    }

    public static void main(String[] args) {
        Optional<String> email = getEmailByUsername("bob");

        email.ifPresentOrElse(
            System.out::println,
            () -> System.out.println("Email not found")
        );
    }
}
```

---

## ✅ Functional Interface & Lambda

### Custom functional interface:

```java
@FunctionalInterface
interface Greeting {
    void sayHello(String name);
}
```

### Using lambda:

```java
public class Greeter {
    public static void main(String[] args) {
        Greeting greet = name -> System.out.println("Hello, " + name + "!");
        greet.sayHello("World");
    }
}
```

---

## 📘 Little Notes on Java 8+ Features

### Lambda Expressions

- Syntax: `(parameters) -> expression`
- Example: `(a, b) -> a + b`

### Method References

- Instead of `x -> System.out.println(x)`, use: `System.out::println`

### Stream API Highlights

| Method         | Purpose                               |
|----------------|----------------------------------------|
| `.filter()`    | Filters based on a predicate           |
| `.map()`       | Transforms each element                |
| `.collect()`   | Collects result into a list, set, etc. |
| `.sorted()`    | Sorts elements                         |
| `.count()`     | Returns number of elements             |

### Optional API

| Method         | Purpose                               |
|----------------|----------------------------------------|
| `.isPresent()` | Checks if value exists                 |
| `.get()`       | Gets value (not recommended alone)     |
| `.orElse()`    | Returns default if empty               |
| `.ifPresent()` | Executes logic if present              |

---

## 🎯 Summary

This example shows how Java 8+ features:

- Help reduce boilerplate
- Provide a functional style of coding
- Avoid `NullPointerException` with `Optional`
- Simplify data processing using Streams and Lambdas

---

💡 You’ll find these used everywhere in:
- **Spring Boot** (e.g., `.map()`, `Optional<>`, method references)
- **Reactive programming**
- **REST APIs for transforming DTOs**
- **Functional programming patterns in modern Java**

Let me know if you want examples for **Collectors.groupingBy**, **flatMap**, or **parallelStream**!
