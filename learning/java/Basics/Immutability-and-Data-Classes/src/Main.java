//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Transaction tx = new Transaction(250.75, "Alice", "Bob");
        System.out.println(tx);

        // Attempting to mutate (no setters exist)
        // tx.amount = 300; // ❌ Not allowed

        // Thread safety: Multiple threads can safely read this object
        Runnable task = () -> System.out.println("Thread: " + Thread.currentThread().getName() + " -> " + tx);
        new Thread(task).start();
        new Thread(task).start();
    }
}