# 🎨 Design Patterns in Java – Real-World Examples

Design Patterns are **proven solutions** to common software design problems. They make your code **more flexible, reusable, and easier to maintain**—especially in large-scale systems.

---

## 📦 Categories of Design Patterns

| Category        | Patterns                          |
|----------------|-----------------------------------|
| Creational      | Singleton, Factory, Builder       |
| Structural      | Adapter, Decorator, Facade        |
| Behavioral      | Strategy, Observer, Command       |

---

## 🧱 1. Singleton Pattern – One Instance Only

**Ensures a class has only one instance and provides a global point of access.**

```java
public class DatabaseConnection {
    private static DatabaseConnection instance;

    private DatabaseConnection() {
        System.out.println("Connecting to DB...");
    }

    public static synchronized DatabaseConnection getInstance() {
        if (instance == null) {
            instance = new DatabaseConnection();
        }
        return instance;
    }

    public void query(String sql) {
        System.out.println("Executing: " + sql);
    }
}
```

**Usage:**

```java
DatabaseConnection db = DatabaseConnection.getInstance();
db.query("SELECT * FROM users");
```

✅ Used in: Logging, Database connections, Configuration managers.

---

## 🏭 2. Factory Pattern – Create Objects Without Exposing Logic

**Creates objects without specifying the exact class to create.**

```java
public interface Notification {
    void send(String to, String msg);
}

public class EmailNotification implements Notification {
    public void send(String to, String msg) {
        System.out.println("Email to " + to + ": " + msg);
    }
}

public class SMSNotification implements Notification {
    public void send(String to, String msg) {
        System.out.println("SMS to " + to + ": " + msg);
    }
}

public class NotificationFactory {
    public static Notification create(String type) {
        return switch (type.toLowerCase()) {
            case "email" -> new EmailNotification();
            case "sms" -> new SMSNotification();
            default -> throw new IllegalArgumentException("Unknown type");
        };
    }
}
```

**Usage:**

```java
Notification notifier = NotificationFactory.create("email");
notifier.send("john@example.com", "Welcome!");
```

✅ Used in: Spring's `ApplicationContext`, UI component generation, service instantiation.

---

## 🧠 3. Strategy Pattern – Change Behavior at Runtime

**Defines a family of algorithms and lets the caller choose which one to use.**

```java
public interface PaymentStrategy {
    void pay(int amount);
}

public class CreditCardPayment implements PaymentStrategy {
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " with credit card");
    }
}

public class PayPalPayment implements PaymentStrategy {
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " using PayPal");
    }
}

public class PaymentContext {
    private PaymentStrategy strategy;

    public PaymentContext(PaymentStrategy strategy) {
        this.strategy = strategy;
    }

    public void payBill(int amount) {
        strategy.pay(amount);
    }
}
```

**Usage:**

```java
PaymentContext context = new PaymentContext(new PayPalPayment());
context.payBill(50);
```

✅ Used in: Sorting algorithms, authentication methods, billing strategies.

---

## 👀 4. Observer Pattern – Publish/Subscribe

**One-to-many relationship: when one object changes state, all dependents are notified.**

```java
import java.util.*;

public interface Subscriber {
    void update(String news);
}

public class EmailSubscriber implements Subscriber {
    public void update(String news) {
        System.out.println("Email received: " + news);
    }
}

public class NewsPublisher {
    private List<Subscriber> subscribers = new ArrayList<>();

    public void subscribe(Subscriber s) {
        subscribers.add(s);
    }

    public void notifyAll(String news) {
        for (Subscriber s : subscribers) {
            s.update(news);
        }
    }
}
```

**Usage:**

```java
NewsPublisher publisher = new NewsPublisher();
publisher.subscribe(new EmailSubscriber());

publisher.notifyAll("Breaking News: Java 21 Released!");
```

✅ Used in: Event handling, UI frameworks, message queues, Spring’s `ApplicationEventPublisher`.

---

## 🧱 5. Builder Pattern – Construct Complex Objects Step by Step

**Separates the construction of a complex object from its representation.**

```java
public class User {
    private String name;
    private String email;
    private int age;

    private User(Builder builder) {
        this.name = builder.name;
        this.email = builder.email;
        this.age = builder.age;
    }

    public static class Builder {
        private String name;
        private String email;
        private int age;

        public Builder setName(String name) {
            this.name = name; return this;
        }

        public Builder setEmail(String email) {
            this.email = email; return this;
        }

        public Builder setAge(int age) {
            this.age = age; return this;
        }

        public User build() {
            return new User(this);
        }
    }
}
```

**Usage:**

```java
User user = new User.Builder()
    .setName("Alice")
    .setEmail("alice@example.com")
    .setAge(28)
    .build();
```

✅ Used in: Lombok’s `@Builder`, DTO building, HTTP clients.

---

## 🧩 Bonus Patterns You Should Explore

| Pattern       | Use Case |
|---------------|----------|
| **Adapter**    | Wrap incompatible interfaces |
| **Decorator**  | Add behavior dynamically |
| **Command**    | Encapsulate a request as an object |
| **Facade**     | Provide a simplified API over a complex subsystem |
| **Proxy**      | Provide a surrogate for another object |
| **Chain of Responsibility** | Pass request along chain of handlers |

---

## 📘 Little Notes on Design Patterns

- Patterns **aren't frameworks**, they're **reusable solutions**.
- Often combine multiple patterns (e.g., Spring uses Factory + Proxy + Strategy).
- Knowing **when to use which pattern** is key to good software architecture.
- Many patterns are already used **under the hood** in Java libraries.

---

## ✅ Summary

Java Design Patterns help you:

- Reuse and scale code logically
- Apply clean design principles (like SOLID)
- Solve common problems in software design
- Communicate intentions clearly with your team

---

## 🛠 Real-World Uses

| Pattern        | Real-World Use |
|----------------|----------------|
| Singleton      | Spring `ApplicationContext` |
| Factory        | `DriverManager.getConnection()` |
| Strategy       | `Comparator`, `Collections.sort()` |
| Observer       | JavaBeans event model, listeners |
| Builder        | `StringBuilder`, `Stream.Builder` |

