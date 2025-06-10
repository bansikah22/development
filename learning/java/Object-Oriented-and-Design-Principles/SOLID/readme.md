# 🧱 SOLID Principles in Java – Write Clean, Scalable & Maintainable Code

The **SOLID principles** are five design principles intended to make software **more understandable, flexible, and maintainable**. These are widely used in large-scale, enterprise-level Java applications and frameworks like Spring.

---

## 📦 What is SOLID?

| Principle | Name                             | Description |
|----------|----------------------------------|-------------|
| S         | **Single Responsibility Principle (SRP)** | One class = one reason to change |
| O         | **Open/Closed Principle (OCP)**         | Open for extension, closed for modification |
| L         | **Liskov Substitution Principle (LSP)** | Subclasses should be substitutable for parent classes |
| I         | **Interface Segregation Principle (ISP)** | Prefer small, specific interfaces over big, general ones |
| D         | **Dependency Inversion Principle (DIP)** | Depend on abstractions, not concretions |

---

## 🎯 Real-World Example: Notification System

We'll design a **notification system** that demonstrates all 5 SOLID principles.

---

## ✅ S – Single Responsibility Principle (SRP)

```java
// Class handles only notification sending
public class EmailService {
    public void sendEmail(String to, String message) {
        System.out.println("Sending email to " + to + ": " + message);
    }
}

// Class handles only user management
public class UserService {
    public void registerUser(String name, String email) {
        // logic to save user
        System.out.println("User registered: " + name);
    }
}
```

📌 **Each class has one reason to change** (e.g., change email logic ≠ user registration).

---

## ✅ O – Open/Closed Principle (OCP)

```java
public interface Notifier {
    void send(String to, String message);
}

public class EmailNotifier implements Notifier {
    public void send(String to, String message) {
        System.out.println("Email: " + message + " to " + to);
    }
}

public class SMSNotifier implements Notifier {
    public void send(String to, String message) {
        System.out.println("SMS: " + message + " to " + to);
    }
}

// App logic remains unchanged while new notifiers are added
public class NotificationService {
    private final Notifier notifier;

    public NotificationService(Notifier notifier) {
        this.notifier = notifier;
    }

    public void notifyUser(String to, String message) {
        notifier.send(to, message);
    }
}
```

📌 **Class is open for extension** (new types of notifications) but **closed for modification**.

---

## ✅ L – Liskov Substitution Principle (LSP)

```java
public class Bird {
    public void fly() {
        System.out.println("Flying");
    }
}

public class Sparrow extends Bird {
    // OK – supports flying
}

public class Ostrich extends Bird {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Ostrich can't fly");
    }
}
```

📛 **Violation** of LSP – `Ostrich` shouldn't inherit from `Bird` if it can't fly.

✅ Correct it:

```java
public interface Bird {}
public interface Flyable {
    void fly();
}

public class Sparrow implements Bird, Flyable {
    public void fly() {
        System.out.println("Sparrow flying");
    }
}

public class Ostrich implements Bird {
    // Does not implement Flyable
}
```

📌 Subtypes should **honor the behavior contract** of their base class/interface.

---

## ✅ I – Interface Segregation Principle (ISP)

```java
public interface Printer {
    void print();
    void scan();
    void fax();
}
```

📛 Too big! Not all printers support all features.

✅ Split into smaller interfaces:

```java
public interface Printable {
    void print();
}

public interface Scannable {
    void scan();
}

public class BasicPrinter implements Printable {
    public void print() {
        System.out.println("Basic printing");
    }
}

public class AdvancedPrinter implements Printable, Scannable {
    public void print() {
        System.out.println("Advanced printing");
    }

    public void scan() {
        System.out.println("Scanning");
    }
}
```

📌 **Clients should not be forced to depend on interfaces they do not use**.

---

## ✅ D – Dependency Inversion Principle (DIP)

```java
// Low-level module
public class EmailNotifier {
    public void send(String to, String msg) {
        System.out.println("Email sent: " + msg);
    }
}

// High-level module tightly coupled to EmailNotifier
public class NotificationManager {
    private EmailNotifier notifier = new EmailNotifier();

    public void alert(String to, String msg) {
        notifier.send(to, msg);
    }
}
```

📛 Violates DIP – high-level module depends on low-level one.

✅ Use abstraction:

```java
public interface Notifier {
    void send(String to, String msg);
}

public class EmailNotifier implements Notifier {
    public void send(String to, String msg) {
        System.out.println("Email sent: " + msg);
    }
}

public class NotificationManager {
    private final Notifier notifier;

    public NotificationManager(Notifier notifier) {
        this.notifier = notifier;
    }

    public void alert(String to, String msg) {
        notifier.send(to, msg);
    }
}
```

📌 **High-level modules should depend on abstractions**.

---

## 📘 Little Notes on SOLID

| Principle | Benefit |
|----------|---------|
| SRP       | Classes are easier to maintain and test |
| OCP       | Add new features without touching old code |
| LSP       | Prevent unexpected behaviors in subclasses |
| ISP       | Avoid bloated interfaces and unused methods |
| DIP       | Promotes flexibility and testability (e.g. via dependency injection) |

---

## 🎯 Summary

The SOLID principles guide you to:

✅ **Break large classes** into smaller, focused ones  
✅ **Extend behavior** without modifying core logic  
✅ **Create safe and replaceable inheritance**  
✅ **Build flexible interfaces**  
✅ **Promote loosely coupled architecture**

---

💡 Widely used in:

- Spring Framework (e.g., `@Service`, `@Repository`, `@Component`)
- RESTful API designs
- Dependency Injection containers
- Modular monoliths & microservices

