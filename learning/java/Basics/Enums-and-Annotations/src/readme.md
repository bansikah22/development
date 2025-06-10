# 🏷️ Java Enums & Annotations – Real-World Example

This example demonstrates how **Enums** and **Annotations** work in Java through a simulated **task management system** where:

- Tasks have different statuses using **Enums**.
- We use a custom annotation to mark methods that require **admin privileges**.
- Reflection is used to check the annotation at runtime.

---

## ⚙️ Enum: TaskStatus

```java
public enum TaskStatus {
    TODO,
    IN_PROGRESS,
    COMPLETED,
    BLOCKED
}
```

---

## 🏷️ Custom Annotation: RequiresAdmin

```java
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface RequiresAdmin {
}
```

- The `@Retention(RetentionPolicy.RUNTIME)` means this annotation is available at runtime via reflection.

---

## 📝 Task Class

```java
public class Task {
    private String name;
    private TaskStatus status;

    public Task(String name, TaskStatus status) {
        this.name = name;
        this.status = status;
    }

    public void setStatus(TaskStatus status) {
        this.status = status;
    }

    public TaskStatus getStatus() {
        return status;
    }

    public String getName() {
        return name;
    }
}
```

---

## 🛠️ TaskManager Class with Admin-Only Methods

```java
import java.lang.reflect.Method;

public class TaskManager {
    private boolean isAdmin;

    public TaskManager(boolean isAdmin) {
        this.isAdmin = isAdmin;
    }

    public void updateTaskStatus(Task task, TaskStatus newStatus) throws Exception {
        if (!checkAdminPrivileges("updateTaskStatus")) {
            throw new SecurityException("Admin privileges required to update task status.");
        }
        task.setStatus(newStatus);
        System.out.println("Task '" + task.getName() + "' status updated to " + newStatus);
    }

    @RequiresAdmin
    public void deleteTask(Task task) {
        System.out.println("Task '" + task.getName() + "' deleted.");
    }

    private boolean checkAdminPrivileges(String methodName) throws Exception {
        Method method = this.getClass().getMethod(methodName, Task.class);
        if (method.isAnnotationPresent(RequiresAdmin.class)) {
            return isAdmin;
        }
        return true; // No annotation means no admin check required
    }
}
```

---

## 🚀 Main Class to Demonstrate Usage

```java
public class Main {
    public static void main(String[] args) {
        Task task1 = new Task("Write report", TaskStatus.TODO);
        TaskManager adminManager = new TaskManager(true);
        TaskManager userManager = new TaskManager(false);

        try {
            // Admin can update status
            adminManager.updateTaskStatus(task1, TaskStatus.IN_PROGRESS);

            // Non-admin tries to update status (should throw exception)
            userManager.updateTaskStatus(task1, TaskStatus.COMPLETED);
        } catch (SecurityException se) {
            System.out.println("SecurityException: " + se.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Admin deletes task
        adminManager.deleteTask(task1);

        // Output the final status
        System.out.println("Final status of task '" + task1.getName() + "': " + task1.getStatus());
    }
}
```

---

## ✅ Output

```
Task 'Write report' status updated to IN_PROGRESS
SecurityException: Admin privileges required to update task status.
Task 'Write report' deleted.
Final status of task 'Write report': IN_PROGRESS
```

---

## 📘 Little Notes About Enums & Annotations in Java

### 🏷️ Enums
- Enums represent a fixed set of constants (e.g., TaskStatus).
- Useful to represent states, categories, and more.
- Type-safe alternative to using `int` or `String` constants.
- Can have fields, methods, and constructors.

### 🏷️ Annotations
- Provide metadata about code (methods, classes, variables).
- Can be built-in (e.g., `@Override`, `@Deprecated`) or custom.
- Custom annotations can be processed at **compile-time** or **runtime**.
- Used heavily in frameworks (like Spring) to define behavior declaratively.
- `@Retention` controls annotation availability (source, class, runtime).

---

## ✅ Summary

This example shows how Java Enums and Annotations:

- Use Enums to clearly define and use a set of constants (task statuses).
- Use custom annotations to **mark and enforce behavior** (admin-only methods).
- Use reflection to **inspect annotations at runtime** for security checks.
- Help build **clean, readable, and maintainable** code often used in enterprise frameworks.

---
