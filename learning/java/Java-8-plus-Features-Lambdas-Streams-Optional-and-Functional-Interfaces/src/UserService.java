import java.util.*;
import java.util.stream.Collectors;

public class UserService {
    public static void main(String[] args) {
        List<User> users = List.of(
                new User("alice", "alice@example.com", "admin"),
                new User("bob", "bob@example.com", "user"),
                new User("carol", "carol@example.com", "admin"),
                new User("dave", "dave@example.com", "user")
        );

        // Filter only admins
        List<User> admins = users.stream()
                .filter(u -> "admin".equals(u.getRole()))
                .collect(Collectors.toList());

        System.out.println("Admins:");
        admins.forEach(System.out::println);
    }
}