package com.bansikah.datastructure.maps;

import java.util.HashMap;
import java.util.Map;

public class WorkingWithMaps2 {

    public static void main(String [] args){
        // Create an immutable map with Person objects as keys and integers as values
        Map<Person, Integer> people = Map.of(
                new Person("John", 20), 1,
                new Person("Jane", 25), 2,
                new Person("Noel", 22), 3,
                new Person("Draxler", 30), 4
        );

        // Create a mutable HashMap with Person objects as keys and integers as values
        Map<Person, Integer> people2 = new HashMap<>();
        people2.put(new Person("John", 20), 1);
        people2.put(new Person("Jane", 25), 2);
        people2.put(new Person("Noel", 22), 3);
        people2.put(new Person("Draxler", 30), 4);

        // Iterate over the keys of the immutable map and print each key-value pair
        for (Person key : people.keySet()) {
            System.out.println(key + " : " + people.get(key));
        }

        // Iterate over the keys of the mutable map and print each key-value pair
        for (Person key : people2.keySet()) {
            System.out.println(key + " : " + people2.get(key));
        }

        // Print the size of the immutable map
        System.out.println(people.size());

        // Check if the immutable map contains a specific key
        System.out.println(people.containsKey(new Person("John", 20)));

        // Check if the immutable map contains a specific value
        System.out.println(people.containsValue(1));

        // Attempt to get a value from the mutable map using an incorrect key type (will print null)
        System.out.println(people2.get(1));

        // Check if the mutable map contains a specific key (incorrect key type, will print false)
        System.out.println(people2.containsKey(4));

        // Check if the mutable map contains a specific value
        System.out.println(people2.containsValue(3));

        // Print the entry set of the mutable map
        System.out.println(people2.entrySet());

        // Remove a key-value pair from the mutable map
        people2.remove(new Person("John", 20));

        // Print the mutable map after removing a key-value pair
        System.out.println(people2);

        // Clear the mutable map
        people2.clear();

        // Print the mutable map after clearing it
        System.out.println(people2);

        // Check if the mutable map is empty
        System.out.println(true);

        // Create a map of strings and strings
        Map<String, String> colors = Map.of(
                "Red", "#FF0000",
                "Blue", "#0000FF",
                "Green", "#00FF00"
        );

        // Print the map of colors
        System.out.println(colors);

        // Print the size of the map of colors
        System.out.println(colors.size());
    }

    // Define a record to represent a person with a name and age
    record Person(String name, int age) { }
}