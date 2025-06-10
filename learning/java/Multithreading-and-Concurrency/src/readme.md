# ⚙️ Multithreading & Concurrency in Java

Java supports **multithreading** and **concurrency** to build fast, responsive, and scalable applications. From background tasks to parallel processing, Java provides powerful APIs like `Thread`, `synchronized`, `ExecutorService`, `Callable`, and more.

---

## 🧠 Why Multithreading?

- Efficient CPU usage
- Perform I/O + computation concurrently
- Handle multiple tasks in parallel (e.g., web requests)
- Build scalable systems (e.g., thread pools)

---

## 🔧 Real-World Scenario: Email Sender with Thread Pool

Imagine a system that sends emails to users. Instead of sending them one at a time (blocking), we can send them concurrently using a **thread pool**.

---

## 📦 Step-by-Step Implementation

### ✅ 1. EmailSender Task (Implements `Runnable`)

```java
public class EmailSender implements Runnable {

    private final String recipient;

    public EmailSender(String recipient) {
        this.recipient = recipient;
    }

    @Override
    public void run() {
        System.out.println("Sending email to " + recipient + " - " + Thread.currentThread().getName());
        try {
            Thread.sleep(1000); // Simulate sending time
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println("Email sent to " + recipient);
    }
}
```

---

### ✅ 2. Thread Pool with `ExecutorService`

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class EmailServiceApp {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3); // Pool of 3 threads

        String[] recipients = {"alice@example.com", "bob@example.com", "carol@example.com", "dave@example.com"};

        for (String recipient : recipients) {
            executor.submit(new EmailSender(recipient));
        }

        executor.shutdown(); // No more tasks accepted
    }
}
```

---

## 🔒 Synchronized Keyword Example

To ensure **thread safety** when multiple threads access shared data:

```java
public class Counter {
    private int count = 0;

    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}
```

Used with multiple threads:

```java
public class CounterApp {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        Runnable task = () -> {
            for (int i = 0; i < 1000; i++) counter.increment();
        };

        Thread t1 = new Thread(task);
        Thread t2 = new Thread(task);

        t1.start(); t2.start();
        t1.join(); t2.join();

        System.out.println("Final count: " + counter.getCount()); // Should be 2000
    }
}
```

---

## 📘 Little Notes About Concurrency

### `ExecutorService`

- Manages thread lifecycle
- Methods: `submit()`, `shutdown()`, `invokeAll()`, etc.

### `Callable` vs `Runnable`

- `Callable<T>` returns a result and can throw exceptions
- Used with `Future<T>` to get results asynchronously

### Thread Safety

- Use `synchronized` or `ReentrantLock`
- Avoid shared mutable state
- Prefer **immutable objects** and **thread-local variables**

---

## 🔧 Additional Concepts

| Concept           | Purpose                                               |
|-------------------|--------------------------------------------------------|
| `Executors`       | Factory methods to create thread pools                 |
| `Future<T>`       | Represents result of async computation                 |
| `CountDownLatch`  | Wait until multiple threads complete                   |
| `Semaphore`       | Limit access to a shared resource                      |
| `ConcurrentHashMap` | Thread-safe hash map                                 |

---

## 🧵 Summary

This example demonstrates:

- How to use `ExecutorService` to manage multiple threads efficiently
- How `synchronized` ensures thread safety
- Real-world usage in background services like email notifications
- Core building blocks of Java concurrency

---

💡 You’ll see concurrency used heavily in:
- **Web servers (Tomcat, Spring Boot async controllers)**
- **Message consumers (Kafka, RabbitMQ listeners)**
- **Parallel data processing (Streams, Fork/Join)**
- **Android apps (UI threading, AsyncTask, Executors)**

Let me know if you'd like to explore **`CompletableFuture`**, **Java Streams in parallel**, or **Locks and Semaphores**!
