import java.util.Optional;

public class EmailService {
    public static Optional<String> getEmailByUsername(String username) {
        if ("bob".equals(username)) {
            return Optional.of("bob@example.com");
        } else {
            return Optional.empty(); // user not found
        }
    }

    public static void main(String[] args) {
        Optional<String> email = getEmailByUsername("bob");

        email.ifPresentOrElse(
            System.out::println,
            () -> System.out.println("Email not found")
        );
    }
}
