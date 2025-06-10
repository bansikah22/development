# 🛡️ Immutability & Data Classes in Java

Immutability is a key principle for building **robust**, **thread-safe**, and **maintainable** code—especially in multithreaded environments. In Java, immutable classes ensure that once an object is created, its state cannot change.

---

## ✅ What is an Immutable Class?

An **immutable class**:
- Has all fields `final`
- Fields are set only once via the constructor
- No setter methods
- Class is `final` (optional, but prevents subclass mutation)
- For mutable fields (like lists), defensive copies are used

---

## 📦 Real-World Scenario: Bank Transaction Record

```java
import java.time.LocalDateTime;
import java.util.UUID;

public final class Transaction {

    private final String transactionId;
    private final double amount;
    private final LocalDateTime timestamp;
    private final String sender;
    private final String receiver;

    public Transaction(double amount, String sender, String receiver) {
        this.transactionId = UUID.randomUUID().toString();
        this.amount = amount;
        this.timestamp = LocalDateTime.now();
        this.sender = sender;
        this.receiver = receiver;
    }

    public String getTransactionId() {
        return transactionId;
    }

    public double getAmount() {
        return amount;
    }

    public LocalDateTime getTimestamp() {
        return timestamp;
    }

    public String getSender() {
        return sender;
    }

    public String getReceiver() {
        return receiver;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "transactionId='" + transactionId + '\'' +
                ", amount=" + amount +
                ", timestamp=" + timestamp +
                ", sender='" + sender + '\'' +
                ", receiver='" + receiver + '\'' +
                '}';
    }
}
```

---

## 🎯 Using the Immutable Class

```java
public class TransactionApp {
    public static void main(String[] args) {
        Transaction tx = new Transaction(250.75, "Alice", "Bob");
        System.out.println(tx);

        // Attempting to mutate (no setters exist)
        // tx.amount = 300; // ❌ Not allowed

        // Thread safety: Multiple threads can safely read this object
        Runnable task = () -> System.out.println("Thread: " + Thread.currentThread().getName() + " -> " + tx);
        new Thread(task).start();
        new Thread(task).start();
    }
}
```

---

## 🧠 Why Use Immutable Objects?

- **Thread-Safe by Design** – No synchronization needed for reads
- **Reliable** – Once created, state never changes (no side effects)
- **Easy to Cache** – Reuse objects without fear of mutation
- **Functional-Style Programming** – Encourages data immutability

---

## 📘 Little Notes About Immutability & Data Classes

### Java Record Classes (Since Java 14+)

A concise way to create immutable data holders:

```java
public record User(String username, String email) { }
```

- Automatically generates:
    - `final` fields
    - `constructor`
    - `getters`
    - `equals()`, `hashCode()`, `toString()`

**Example:**

```java
public class RecordExample {
    public static void main(String[] args) {
        User user = new User("john_doe", "john@example.com");
        System.out.println(user);
    }
}
```

### Java Beans vs Records

| Feature      | Java Bean                | Java Record               |
|--------------|--------------------------|---------------------------|
| Mutability   | Typically mutable        | Immutable by default      |
| Boilerplate  | Needs getters/setters    | Compact syntax            |
| Use Case     | General OOP              | Data-carrier classes      |

---

## 🧵 Summary

This example demonstrates:

- How to design **immutable** classes for thread-safe data
- How to apply **best practices** in building safe concurrent systems
- How to use **records** (Java 14+) for cleaner data classes
- Why **immutability** improves code stability and readability

---

💡 You’ll find immutability in action in libraries and frameworks like:
- Spring (DTOs and config objects)
- Java Streams
- Functional libraries (Vavr, Reactor)
- Domain-Driven Design (Value Objects)

Let me know if you'd like to explore **immutable collections**, **builders**, or **records in Spring**!
