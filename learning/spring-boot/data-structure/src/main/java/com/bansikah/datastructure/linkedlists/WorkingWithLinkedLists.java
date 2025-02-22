package com.bansikah.datastructure.linkedlists;

import java.util.LinkedList;

public class WorkingWithLinkedLists {
    public static void main(String [] args){
        // Create a linked list of integers
        LinkedList<Integer> numbers = new LinkedList<>(); // Initialize a linked list of integers
        numbers.add(10); // Add 10 to the linked list
        numbers.add(20); // Add 20 to the linked list
        numbers.add(30); // Add 30 to the linked list
        numbers.add(40); // Add 40 to the linked list
        numbers.add(50); // Add 50 to the linked list

        for (int number : numbers) { // Loop through the linked list
            System.out.println(number); // Print each element of the linked list
        }

        // Create a linked list of strings
        LinkedList<String> names = new LinkedList<>(); // Initialize a linked list of strings
        names.add("John"); // Add "John" to the linked list
        names.add("Doe"); // Add "Doe" to the linked list
        names.add("Jane"); // Add "Jane" to the linked list
        names.add("Doe"); // Add "Doe" to the linked list

        for (String name : names) { // Loop through the linked list
            System.out.println(name); // Print each element of the linked list
        }

        System.out.println(names.size()); // Print the size of the linked list
        //System.out.println(names.get(4)); // create an index out of bounds exception

        //creating a linked list of array colors
        LinkedList<String> colors = new LinkedList<>();
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");

        System.out.println(colors); // Print the linked list of colors
        System.out.println(colors.get(1)); // Print the second element of the linked list
        System.out.println(colors.size()); // Print the size of the linked list
        System.out.println(colors.contains("Red")); // Check if the linked list contains "Red"

        // Remove the first element from the linked list
        colors.removeFirst();
        // Print the linked list of colors
        System.out.println(colors);

        // iterate linked list using enhanced for loop
        for(String color : colors){
            System.out.println(color);
        }
    }
}
