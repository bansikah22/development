package com.bansikah.atm;

import java.util.Scanner;

public class ATM {
    private Bank bank;
    private Account currentAccount;
    private Scanner scanner;
    private static final int MAX_ATTEMPTS = 3; // Limit login attempts

    public ATM(Bank bank) {
        this.bank = bank;
        this.scanner = new Scanner(System.in);
    }

    public void start() {
        System.out.println("Welcome to the ATM!");
        authenticateUser();
    }

    private void authenticateUser() {
        int attempts = 0;

        while (attempts < MAX_ATTEMPTS) {
            try {
                System.out.print("Enter Account Number: ");
                int accountNumber = scanner.nextInt();
                System.out.print("Enter PIN: ");
                int pin = scanner.nextInt();

                currentAccount = bank.verifyAccount(accountNumber, pin);

                if (currentAccount != null) {
                    System.out.println("Login successful!");
                    showMenu();
                    return;
                } else {
                    attempts++;
                    System.out.println("Invalid credentials. Attempts left: " + (MAX_ATTEMPTS - attempts));
                }
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter numeric values.");
                scanner.nextLine(); // Clear the input buffer
            }
        }

        System.out.println("Too many failed attempts. Exiting system.");
        System.exit(1);
    }

    private void showMenu() {
        while (true) {
            System.out.println("\nATM Menu:");
            System.out.println("1. Check Balance");
            System.out.println("2. Deposit Money");
            System.out.println("3. Withdraw Money");
            System.out.println("4. Exit");
            System.out.print("Select an option: ");

            try {
                int choice = scanner.nextInt();
                handleTransaction(choice);
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter a number between 1 and 4.");
                scanner.nextLine(); // Clear input buffer
            }
        }
    }

    private void handleTransaction(int choice) {
        switch (choice) {
            case 1:
                System.out.println("Current Balance: $" + currentAccount.getBalance());
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                System.out.println("Thank you for using the ATM. Goodbye!");
                System.exit(0);
                break;
            default:
                System.out.println("Invalid choice. Please select a valid option.");
        }
    }

    private void depositMoney() {
        System.out.print("Enter amount to deposit: ");
        try {
            double amount = scanner.nextDouble();
            if (amount > 0) {
                currentAccount.deposit(amount);
            } else {
                System.out.println("Deposit amount must be greater than zero.");
            }
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter a valid amount.");
            scanner.nextLine(); // Clear input buffer
        }
    }

    private void withdrawMoney() {
        System.out.print("Enter amount to withdraw: ");
        try {
            double amount = scanner.nextDouble();
            if (amount > 0) {
                currentAccount.withdraw(amount);
            } else {
                System.out.println("Withdrawal amount must be greater than zero.");
            }
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter a valid amount.");
            scanner.nextLine(); // Clear input buffer
        }
    }
}
