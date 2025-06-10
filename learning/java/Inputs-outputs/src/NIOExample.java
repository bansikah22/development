import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.file.*;

public class NIOExample {

    private static final Path PATH = Paths.get("example_nio.txt");

    public static void writeToFile(String content) {
        byte[] bytes = content.getBytes();
        ByteBuffer buffer = ByteBuffer.wrap(bytes);

        try (FileChannel channel = FileChannel.open(PATH, StandardOpenOption.CREATE, StandardOpenOption.WRITE)) {
            channel.write(buffer);
            System.out.println("NIO: Written to file successfully.");
        } catch (IOException e) {
            System.err.println("NIO Write Error: " + e.getMessage());
        }
    }

    public static void readFromFile() {
        try (FileChannel channel = FileChannel.open(PATH, StandardOpenOption.READ)) {
            ByteBuffer buffer = ByteBuffer.allocate(1024);
            System.out.println("NIO: Reading from file:");

            int bytesRead = channel.read(buffer);
            while (bytesRead != -1) {
                buffer.flip(); // switch buffer from writing mode to reading mode

                while (buffer.hasRemaining()) {
                    System.out.print((char) buffer.get());
                }

                buffer.clear(); // clear for next read
                bytesRead = channel.read(buffer);
            }
            System.out.println(); // newline after file content
        } catch (IOException e) {
            System.err.println("NIO Read Error: " + e.getMessage());
        }
    }
}