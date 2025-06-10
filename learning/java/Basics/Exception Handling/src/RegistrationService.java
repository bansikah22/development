public class RegistrationService {
    public void registerUser(String username) throws InvalidUserException{
        if (username == null || username.length() < 3) {
            throw new InvalidUserException("Username must be at least 3 characters long.");
        }

        // Simulating success
        System.out.println("User '" + username + "' registered successfully.");
    }
}
