package com.bansikah.datastructure.sets;

import java.util.Set;

public class WorkingWithSets {
    public static void main(String [] args) {
        //another way of creating set, this set is unmodifiable
        Set.of(
                "John",
                "Doe",
                "Jane",
                "Doe"
        );

        // Create a set of integers
        Set<Integer> numbers = Set.of(10, 20, 30, 40, 50); // Initialize a set of integers
        for (int number : numbers) { // Loop through the set
            System.out.println(number); // Print each element of the set
        }

        // Create a set of strings
        Set<String> names = Set.of("John", "Doe", "Jane", "Doe"); // Initialize a set of strings
        for (String name : names) { // Loop through the set
            System.out.println(name); // Print each element of the set
        }

        System.out.println(names.size()); // Print the size of the set
        System.out.println(names.contains("John")); // Check if the set contains "John"

        // Create a set of strings
        Set<String> colors = Set.of("Red", "Blue", "Green"); // Initialize a set of strings
        for (String color : colors) { // Loop through the set
            System.out.println(color); // Print each element of the set
        }

        System.out.println(colors); // Print the set of colors
        System.out.println(colors.size()); // Print the size of the set
        System.out.println(colors.contains("Red")); // Check if the set contains "Red"

        // Remove the first element from the set
        //colors.removeFirst(); // This will throw an UnsupportedOperationException

        // iterate set using enhanced for loop
        for (String color : colors) {
            System.out.println(color);
        }


    }
}
