package com.bansikah.datastructure.maps.hashmaps;

import java.util.HashMap;
import java.util.Map;

public class WorkingWithHashMaps {
    public static void main(String [] args){
        // Create a HashMap to store Student-Diamond pairs
        Map<Student, Diamond> map = new HashMap<>();
        // Add a Student-Diamond pair to the map
        map.put(new Student("John"), new Diamond("African Diamond"));

        // Iterate over the keys (Students) in the map and print each key-value pair
        for (Student student : map.keySet()) {
            System.out.println(student + " : " + map.get(student));
        }

        // Print the hash code of a new Student object with the name "John"
        System.out.println(new Student("John").hashCode());
        // Print the hash code of another new Student object with the name "John"
        System.out.println(new Student("John").hashCode());
        // Check if the map contains a key for a new Student object with the name "John"
        System.out.println(map.containsKey(new Student("John")));
        // Retrieve and print the value associated with a new Student object with the name "John"
        System.out.println(map.get(new Student("John")));
    }

    // Define a Student class with a name field
    static class Student{
        String name;

        // Constructor to initialize the name field
        public Student(String name){
            this.name = name;
        }

        // Override the equals method to compare Student objects based on the name field
        @Override
        public boolean equals(Object o){
            if(this == o) return true;
            if(o == null || getClass() != o.getClass()) return false;
            Student student = (Student) o;
            return name.equals(student.name);
        }

        // Override the hashCode method to generate a hash code based on the name field
        @Override
        public int hashCode(){
            return name.hashCode();
        }

        // Override the toString method to provide a string representation of a Student object
        @Override
        public String toString(){
            return "Student{" +
                    "name='" + name + '\'' +
                    '}';
        }
    }

    // Define a Diamond record with a name field
    record Diamond(String name) {}
}