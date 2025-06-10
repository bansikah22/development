package com.bansikah.atm;

public class Main {
    public static void main(String[] args) {
        Bank bank = new Bank();

        // Add default test accounts
        bank.addAccount(new Account(1234, 1234, 500.0));
        bank.addAccount(new Account(5678, 5678, 1000.0));

        // Pass the bank instance to ATM
        ATM atm = new ATM(bank);
        atm.start();
    }
}
