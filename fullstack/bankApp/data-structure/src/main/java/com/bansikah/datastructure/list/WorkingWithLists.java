package com.bansikah.datastructure.list;

import java.util.ArrayList;
import java.util.List;

public class WorkingWithLists {
    public static void main(String [] args){
        // Create a list of integers
        List<Integer> numbers = new ArrayList<>();// Initialize an array list of integers
        numbers.add(10); // Add 10 to the list
        numbers.add(20); // Add 20 to the list
        numbers.add(30); // Add 30 to the list
        numbers.add(40); // Add 40 to the list
        numbers.add(50); // Add 50 to the list

        for (int number : numbers) { // Loop through the list
            System.out.println(number); // Print each element of the list
        }

        // Create a list of strings
        List<String> names = new ArrayList<>();// Initialize an array list of strings
        names.add("John"); // Add "John" to the list
        names.add("Doe"); // Add "Doe" to the list
        names.add("Jane"); // Add "Jane" to the list
        names.add("Doe"); // Add "Doe" to the list

        for (String name : names) { // Loop through the list
            System.out.println(name); // Print each element of the list
        }

        System.out.println(names.size()); // Print the size of the list
        System.out.println(names.get(4)); // create an index out of bounds exception
    }
}
