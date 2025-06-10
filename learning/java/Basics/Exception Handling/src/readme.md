# 💥 Java Exception Handling – Custom Exceptions, Try-Catch-Finally

Exception handling in Java helps you manage **runtime errors** gracefully, so applications don't crash unexpectedly. It's a fundamental part of building robust and user-friendly applications.

---

## 🧠 Why Exception Handling Matters

- **Separates error-handling from logic**
- **Prevents app crashes**
- **Improves debugging and reliability**
- **Encourages defensive programming**

---

## 🔧 Real-World Scenario: User Registration with Validation

We’ll simulate a registration system that validates a username and throws **custom exceptions** for invalid input.

---

### ✅ 1. Custom Exception Class

```java
public class InvalidUserException extends Exception {
    public InvalidUserException(String message) {
        super(message);
    }
}
```

---

### ✅ 2. Service Class that Validates Input

```java
public class RegistrationService {

    public void registerUser(String username) throws InvalidUserException {
        if (username == null || username.length() < 3) {
            throw new InvalidUserException("Username must be at least 3 characters long.");
        }

        // Simulating success
        System.out.println("User '" + username + "' registered successfully.");
    }
}
```

---

### ✅ 3. Using Try-Catch-Finally in Application

```java
public class App {
    public static void main(String[] args) {
        RegistrationService service = new RegistrationService();

        try {
            service.registerUser("ab");  // too short
        } catch (InvalidUserException e) {
            System.err.println("Registration failed: " + e.getMessage());
        } finally {
            System.out.println("Registration process completed.");
        }
    }
}
```

---

## 📘 Little Notes on Exception Handling

### 🔄 Types of Exceptions

| Type               | Description                          |
|--------------------|--------------------------------------|
| **Checked**        | Must be declared or handled (e.g., `IOException`, `SQLException`) |
| **Unchecked**      | Runtime errors (e.g., `NullPointerException`, `IllegalArgumentException`) |

---

### 🔹 `try-catch-finally` Keywords

| Block       | Purpose                                                  |
|-------------|----------------------------------------------------------|
| `try`       | Wrap code that might throw an exception                 |
| `catch`     | Handle specific exception types                         |
| `finally`   | Runs whether exception occurs or not (clean-up, etc.)   |

---

### ❗ Best Practices

- Catch **specific** exceptions, not generic `Exception`
- Don’t swallow exceptions—**log** them
- Use **custom exceptions** for business logic clarity
- Use `finally` for clean-up tasks like closing files/streams

---

## 🎯 Summary

This example demonstrates how Java Exception Handling:

- Lets you define meaningful **custom exceptions**
- Cleanly separates normal logic from **error handling**
- Helps you **recover or log** when something goes wrong
- Keeps your application **robust** and **user-friendly**

---

💡 You’ll find exception handling used in:

- **Spring Boot** `@ControllerAdvice` & `@ExceptionHandler`
- **REST APIs** for validation & error responses
- **File I/O**, **Database**, and **Network** operations
- **Concurrency & thread-safe code**

Let me know if you want an example involving `try-with-resources` or Spring Boot-style global exception handling!
