package EmailSender;

public class EmailSender implements Runnable {

    private final String recipient;

    public EmailSender(String recipient) {
        this.recipient = recipient;
    }

    @Override
    public void run() {
        System.out.println("Sending email to " + recipient + " - " + Thread.currentThread().getName());
        try {
            Thread.sleep(1000); // Simulate sending time
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println("Email sent to " + recipient);
    }
}