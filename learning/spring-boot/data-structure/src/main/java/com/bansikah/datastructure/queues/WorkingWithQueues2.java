package  com.bansikah.datastructure.queues;
import java.util.LinkedList;
import java.util.Queue;

public class WorkingWithQueues2 {
    public static void main(String [] args){
        // Create a queue to represent a supermarket line
        Queue<Person> supermarket = new LinkedList<>();

        // Add people to the queue
        supermarket.add(new Person("John", 20));
        supermarket.add(new Person("Jane", 25));
        supermarket.add(new Person("Noel", 22));
        supermarket.add(new Person("Draxler", 30));

        // Remove and print the first person in the queue
        System.out.println(supermarket.remove());

        // Peek at the first person in the queue without removing them
        System.out.println(supermarket.peek());

        // Print the number of people currently in the queue
        System.out.println(supermarket.size());

        // Check if a specific person is in the queue
        System.out.println(supermarket.contains(new Person("John", 20)));

        // Remove and print the first person in the queue, or null if the queue is empty
        System.out.println(supermarket.poll());
    }

    // Define a record to represent a person with a name and age
    record Person(String name, int age) { }
}