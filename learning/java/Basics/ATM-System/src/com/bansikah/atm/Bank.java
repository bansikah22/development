package com.bansikah.atm;

import java.util.ArrayList;
import java.util.List;

public class Bank {
    private List<Account> accounts = new ArrayList<>();

    // Adds a new account to the bank
    public void addAccount(Account account) {
        accounts.add(account);
    }

    // Verifies account credentials
    public Account verifyAccount(int accountNumber, int pin) {
        for (Account account : accounts) {
            if (account.getAccountNumber() == accountNumber && account.getPin() == pin) {
                return account; // Account found
            }
        }
        return null; // No match
    }
}
