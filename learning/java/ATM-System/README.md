# ATM System

This is a simple ATM system built in Java that allows users to authenticate, check balances, deposit, and withdraw money. The system follows object-oriented principles and ensures smooth interaction between bank accounts and an ATM interface.

## Features

- User authentication using an account number and PIN.
- Check account balance.
- Deposit money into an account.
- Withdraw money from an account.
- Error handling for invalid inputs and insufficient funds.
- Well-structured code with separate classes for Account, ATM, Bank, User, and Utility functions.

## Prerequisites

- Java Development Kit (JDK) installed (Java 8+).
- Any Java IDE (e.g., IntelliJ IDEA, Eclipse, VS Code) or a command-line terminal.

## Project Structure

```bash
.
├── README.md
└── src
    └── com
        └── bansikah
            └── atm
                ├── Account.java
                ├── ATM.java
                ├── Bank.java
                ├── Main.java
                ├── User.java
                └── Utility.java

```

## Default Test Accounts

To test the application, use the following default accounts:

| Account Number | PIN  | Initial Balance |
|---------------|------|----------------|
| 1234         | 1234 | $500.00        |
| 5678         | 5678 | $1000.00       |

## How to Run

### Using an IDE

1. Open the project in your preferred Java IDE.
2. Run the `Main.java` file.

### Using the Terminal

1. Navigate to the project directory:
   ```sh
   cd atm-system/src/com/bansikah/atm
```
2. Compile the Java files:
```bash
javac com/bansikah/atm/*.java
```
3. Run the program
```bash
java com.bansikah.atm.Main
```

