package com.bansikah.datastructure.arrays;

import java.util.Arrays;

public class WorKingWith2DArrays {
    public static void main(String[] args) {
        int[][] numbers = new int[2][3]; // Initialize a 2D array of integers with 2 rows and 3 columns
        numbers[0][0] = 10; // Assign 10 to the first element
        numbers[0][1] = 20; // Assign 20 to the second element
        numbers[0][2] = 30; // Assign 30 to the third element
        numbers[1][0] = 40; // Assign 40 to the fourth element
        numbers[1][1] = 50; // Assign 50 to the fifth element
        numbers[1][2] = 60; // Assign 60 to the sixth element

        for (int i = 0; i < numbers.length; i++) { // Loop through the rows
            for (int j = 0; j < numbers[i].length; j++) { // Loop through the columns
                System.out.println(numbers[i][j]); // Print each element of the 2D array
            }
        }

        char[][] board = new char[3][3]; // Initialize a 2D array of characters with 3 rows and 3 columns
        for(int i = 0; i < board.length; i++) { // Loop through the rows
            for(int j = 0; j < board[i].length; j++) { // Loop through the columns
                board[i][j] = '-'; // Assign '-' to each element
            }
        }

        char[][] board1 = new char[][]{
                new char[]{'0', '-', '-'},
                new char[]{'0', '-', '-'},
                new char[]{'0', '-', '-'}
        }; // Initialize a 2D array of characters
        System.out.println(Arrays.deepToString(board1)); // Print the 2D array

        board[0][0] = '0'; // Assign '0' to the first element
        board[1][0] = '0'; // Assign '0' to the fifth element
        board[2][0] = '0'; // Assign '0' to the ninth element
        System.out.println(Arrays.deepToString(board)); // Print the 2D array
    }
}
