//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        RegistrationService service = new RegistrationService();

        try {
            service.registerUser("abc");  // too short
        } catch (InvalidUserException e) {
            System.err.println("Registration failed: " + e.getMessage());
        } finally {
            System.out.println("Registration process completed.");
        }
    }
}