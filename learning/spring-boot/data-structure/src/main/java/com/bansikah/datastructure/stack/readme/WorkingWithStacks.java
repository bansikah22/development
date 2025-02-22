package com.bansikah.datastructure.stack.readme;

import java.util.Stack;

public class WorkingWithStacks {
    public static void main(String[] args) {
        // Create a stack of integers
        Stack<Integer> numbers = new Stack<>(); // Initialize a stack of integers
        numbers.push(10); // Push 10 to the stack
        numbers.push(20); // Push 20 to the stack
        numbers.push(30); // Push 30 to the stack
        numbers.push(40); // Push 40 to the stack
        numbers.push(50); // Push 50 to the stack

        while (!numbers.isEmpty()) { // Loop through the stack
            System.out.println(numbers.pop()); // Pop each element of the stack
        }

        // Create a stack of strings
        Stack<String> names = new Stack<>(); // Initialize a stack of strings
        names.push("John"); // Push "John" to the stack
        names.push("Doe"); // Push "Doe" to the stack
        names.push("Jane"); // Push "Jane" to the stack
        names.push("Doe"); // Push "Doe" to the stack

        while (!names.isEmpty()) { // Loop through the stack
            System.out.println(names.pop()); // Pop each element of the stack
        }

        System.out.println(names.size()); // Print the size of the stack(which is always 0) so we can see that the stack is empty
        //System.out.println(names.get(4)); // create an index out of bounds exception

        //creating a stack of array colors
        Stack<String> colors = new Stack<>();
        colors.push("Red");
        colors.push("Blue");
        colors.push("Green");

        System.out.println(colors); // Print the stack of colors
        System.out.println(colors.peek()); // Print the top element of the stack
        System.out.println(colors.size()); // Print the size of the stack
        System.out.println(colors.contains("Red")); // Check if the stack contains "Red"

        // Remove the top element from the stack
        colors.pop();
        // Print the stack of colors
        System.out.println(colors);

        // iterate stack using enhanced for loop
        for (String color : colors) {
            System.out.println(color);
        }
    }
}
