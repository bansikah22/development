package com.bansikah.datastructure.queues;

import java.util.LinkedList;
import java.util.Queue;

public class WorkingWithQueues {
    public static void main(String [] args){
        // Create a queue of integers
        Queue<Integer> numbers = new LinkedList<>(); // Initialize a queue of integers
        numbers.add(10); // Add 10 to the queue
        numbers.add(20); // Add 20 to the queue
        numbers.add(30); // Add 30 to the queue
        numbers.add(40); // Add 40 to the queue
        numbers.add(50); // Add 50 to the queue

        while (!numbers.isEmpty()) { // Loop through the queue
            System.out.println(numbers.remove()); // Remove each element of the queue
        }

        // Create a queue of strings
        Queue<String> names = new LinkedList<>(); // Initialize a queue of strings
        names.add("John"); // Add "John" to the queue
        names.add("Doe"); // Add "Doe" to the queue
        names.add("Jane"); // Add "Jane" to the queue
        names.add("Doe"); // Add "Doe" to the queue

        while (!names.isEmpty()) { // Loop through the queue
            System.out.println(names.remove()); // Remove each element of the queue
        }

        System.out.println(names.size()); // Print the size of the queue(which is always 0) so we can see that the queue is empty
        //System.out.println(names.get(4)); // create an index out of bounds exception

        //creating a queue of array colors
        Queue<String> colors = new LinkedList<>();
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");

        System.out.println(colors); // Print the queue of colors
        System.out.println(colors.peek()); // Print the top element of the queue
        System.out.println(colors.size()); // Print the size of the queue
        System.out.println(colors.contains("Red")); // Check if the queue contains "Red"

        // Remove the top element from the queue
        colors.remove();
        // Print the queue of colors
        System.out.println(colors);

        // iterate queue using enhanced for loop
        for (String color : colors) {
            System.out.println(color);
        }
    }
}
