package com.bansikah.datastructure.maps;

import java.util.HashMap;

public class WorkingWithMaps {

    public static void main(String [] args){
        // Create a map of integers and strings
        HashMap<Integer, String> numbers = new HashMap<>(); // Initialize a hash map of integers and strings
        numbers.put(1, "One"); // Add 1 and "One" to the map
        numbers.put(2, "Two"); // Add 2 and "Two" to the map
        numbers.put(3, "Three"); // Add 3 and "Three" to the map
        numbers.put(4, "Four"); // Add 4 and "Four" to the map
        numbers.put(5, "Five"); // Add 5 and "Five" to the map

        for (int key : numbers.keySet()) { // Loop through the keys of the map
            System.out.println(key + " : " + numbers.get(key)); // Print the key and value of the map
        }

        // Create a map of strings and integers
        HashMap<String, Integer> names = new HashMap<>(); // Initialize a hash map of strings and integers
        names.put("One", 1); // Add "One" and 1 to the map
        names.put("Two", 2); // Add "Two" and 2 to the map
        names.put("Three", 3); // Add "Three" and 3 to the map
        names.put("Four", 4); // Add "Four" and 4 to the map
        names.put("Five", 5); // Add "Five" and 5 to the map

        for (String key : names.keySet()) { // Loop through the keys of the map
            System.out.println(key + " : " + names.get(key)); // Print the key and value of the map
        }

        System.out.println(names.size()); // Print the size of the map
        System.out.println(names.containsKey("One")); // Check if the map contains the key "One"
        System.out.println(names.containsValue(1)); // Check if the map contains the value 1

        // Remove the key "One" from the map
        names.remove("One");
        // Print the map of names
        System.out.println(names);

        // Create a map of strings and strings
        HashMap<String, String> colors = new HashMap<>(); // Initialize a hash map of strings and strings
        colors.put("Red", "#FF0000"); // Add "Red
    }
}
