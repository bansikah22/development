package com.bansikah.datastructure.arrays;

public class TheArrays {
    public static void main(String[] args) {
        int[] numbers = new int[5]; // Initialize an array of integers with a size of 5
        numbers[0] = 10; // Assign 10 to the first element
        numbers[1] = 20; // Assign 20 to the second element
        numbers[2] = 30; // Assign 30 to the third element
        numbers[3] = 40; // Assign 40 to the fourth element
        numbers[4] = 50; // Assign 50 to the fifth element

        for (int number : numbers) { // Loop through the array
            System.out.println(number); // Print each element of the array
        }

        //using for loop
//         (int i = 0; i < numbers.length; i++) { // Loop through the array using an index
//            System.out.println(numbers[i]); // Print each element of the array
//        }

        //using streams to print the array
//        Arrays.stream(numbers).forEach(System.out::println);

        String[] names = {"John", "Doe", "Jane", "Doe"}; // Initialize an array of strings with values
        for (String name : names) { // Loop through the array
            System.out.println(name); // Print each element of the array
        }
        System.out.println(names.length); // Print the length of the array
        System.out.println(names[4]); // create an array out of bounds exception
    }
}
