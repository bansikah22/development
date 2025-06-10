import java.io.*;

public class ClassicIOExample {

    private static final String FILE_PATH = "example.txt";

    public static void writeToFile(String content) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH))) {
            writer.write(content);
            System.out.println("ClassicIO: Written to file successfully.");
        } catch (IOException e) {
            System.err.println("ClassicIO Write Error: " + e.getMessage());
        }
    }

    public static void readFromFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String line;
            System.out.println("ClassicIO: Reading from file:");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("ClassicIO Read Error: " + e.getMessage());
        }
    }
}