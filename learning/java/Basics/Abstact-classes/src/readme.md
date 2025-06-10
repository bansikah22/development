# 💳 Java Abstract Classes & Methods – Real-World Example

This example demonstrates how to use **abstract classes and methods** in Java through a real-world **payment system**. We will define a base abstract class `Payment` and create specific implementations such as `CreditCardPayment`, `PayPalPayment`, and `BankTransferPayment`.

---

## 🧱 Abstract Class: Payment

```java
public abstract class Payment {
    protected double amount;

    public Payment(double amount) {
        this.amount = amount;
    }

    // Abstract method to be implemented by subclasses
    public abstract void processPayment();

    // Concrete method shared by all payment types
    public void printReceipt() {
        System.out.println("Payment of $" + amount + " processed.");
    }
}
```

---

## 💳 CreditCardPayment Class

```java
public class CreditCardPayment extends Payment {
    private String cardNumber;

    public CreditCardPayment(double amount, String cardNumber) {
        super(amount);
        this.cardNumber = cardNumber;
    }

    @Override
    public void processPayment() {
        System.out.println("Processing credit card payment of $" + amount + " using card: " + cardNumber);
    }
}
```

---

## 🅿️ PayPalPayment Class

```java
public class PayPalPayment extends Payment {
    private String email;

    public PayPalPayment(double amount, String email) {
        super(amount);
        this.email = email;
    }

    @Override
    public void processPayment() {
        System.out.println("Processing PayPal payment of $" + amount + " for account: " + email);
    }
}
```

---

## 🏦 BankTransferPayment Class

```java
public class BankTransferPayment extends Payment {
    private String bankAccount;

    public BankTransferPayment(double amount, String bankAccount) {
        super(amount);
        this.bankAccount = bankAccount;
    }

    @Override
    public void processPayment() {
        System.out.println("Processing bank transfer of $" + amount + " to account: " + bankAccount);
    }
}
```

---

## 🚀 Main Class

```java
public class Main {
    public static void main(String[] args) {
        Payment creditCard = new CreditCardPayment(100.0, "1234-5678-9012-3456");
        Payment paypal = new PayPalPayment(75.5, "user@example.com");
        Payment bankTransfer = new BankTransferPayment(200.0, "ACC123456");

        creditCard.processPayment();
        creditCard.printReceipt();

        paypal.processPayment();
        paypal.printReceipt();

        bankTransfer.processPayment();
        bankTransfer.printReceipt();
    }
}
```

---

## ✅ Output

```
Processing credit card payment of $100.0 using card: 1234-5678-9012-3456
Payment of $100.0 processed.
Processing PayPal payment of $75.5 for account: user@example.com
Payment of $75.5 processed.
Processing bank transfer of $200.0 to account: ACC123456
Payment of $200.0 processed.
```

---

## 📘 Little Notes About Abstract Classes

### 🧠 What is an Abstract Class?
- A class that **cannot be instantiated**.
- Can contain:
    - **Abstract methods** (no body, must be implemented by subclasses).
    - **Concrete methods** (with full implementation).

### 💡 Why Use Abstract Classes?
- To enforce a **common interface/contract** while allowing different behaviors.
- Great for **code reuse** and **polymorphism**.
- Supports **partial implementation**.

### ⚖️ Abstract vs Interface
| Feature                | Abstract Class                | Interface                  |
|------------------------|-------------------------------|----------------------------|
| Can have constructors  | ✅ Yes                        | ❌ No                      |
| Can have fields        | ✅ Yes                        | ✅ (public static final)   |
| Supports multiple inheritance | ❌ No                | ✅ Yes                     |
| Can have method bodies | ✅ Yes                        | ✅ (from Java 8 onward)    |

---

## ✅ Summary

This example shows how **abstract classes and methods** in Java:

- Let you define **shared structure** and **enforce behavior contracts**.
- Allow different implementations (`CreditCardPayment`, `PayPalPayment`, `BankTransferPayment`) to follow the same pattern.
- Make the code **more organized, reusable, and extensible**.

> Abstract classes are best used when you have a base class with common functionality and want to enforce specific behavior in the subclasses.

---
