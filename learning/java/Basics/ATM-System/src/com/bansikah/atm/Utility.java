package com.bansikah.atm;

import java.util.Scanner;

public class Utility {
    private static final Scanner scanner = new Scanner(System.in);

    // Reads user input with a prompt
    public static String getUserInput(String prompt) {
        System.out.print(prompt);
        return scanner.nextLine().trim();
    }

    // Validates if an amount is positive
    public static boolean validateAmount(double amount) {
        return amount > 0;
    }
}
