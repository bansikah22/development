package EmailSender;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class EmailServiceApp {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3); // Pool of 3 threads

        String[] recipients = {"alice@example.com", "bob@example.com", "carol@example.com", "dave@example.com"};

        for (String recipient : recipients) {
            executor.submit(new EmailSender(recipient));
        }

        executor.shutdown(); // No more tasks accepted
    }
}
