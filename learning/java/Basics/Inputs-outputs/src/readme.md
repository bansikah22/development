# 📂 Java IO & NIO – Real-World File Handling Example

This example demonstrates how to use **Java IO and NIO** APIs to:

- Read from and write to a text file using classic **IO streams** with buffering.
- Use **NIO Channels and Buffers** for more efficient file operations.
- Handle exceptions and resource management with **try-with-resources**.

---

## ⚙️ Classic IO: Writing and Reading Text Files with Buffered Streams

```java
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
```

---

## ⚙️ NIO: Writing and Reading Files Using Channels and Buffers

```java
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
```

---

## 🚀 Main Class to Demonstrate Both IO and NIO

```java
public class MainIOExample {
    public static void main(String[] args) {
        String content = "Hello, this is a test of Java IO and NIO file handling!\nSecond line of the file.";

        // Classic IO
        ClassicIOExample.writeToFile(content);
        ClassicIOExample.readFromFile();

        System.out.println("--------------");

        // NIO
        NIOExample.writeToFile(content);
        NIOExample.readFromFile();
    }
}
```

---

## ✅ Output

```
ClassicIO: Written to file successfully.
ClassicIO: Reading from file:
Hello, this is a test of Java IO and NIO file handling!
Second line of the file.
--------------
NIO: Written to file successfully.
NIO: Reading from file:
Hello, this is a test of Java IO and NIO file handling!
Second line of the file.
```

---

## 📘 Little Notes About IO & NIO in Java

### Classic IO (`java.io`)
- Uses **streams** to read/write data one byte or character at a time.
- `BufferedReader` and `BufferedWriter` improve performance by buffering data.
- Synchronous and blocking operations.
- Simple and straightforward for basic file handling.
- Uses exceptions like `IOException` for error handling.

### NIO (`java.nio`)
- Stands for **New IO** introduced in Java 1.4 with improved performance.
- Uses **Channels** (like streams but bidirectional) and **Buffers** (containers for data).
- Supports **non-blocking IO** and more scalable file/network operations.
- FileChannel allows file locking, memory-mapped files, and more.
- More complex but more powerful and efficient for large data or advanced use cases.

### Try-With-Resources
- Both examples use `try-with-resources` to automatically close streams/channels and prevent resource leaks.

---

## ✅ Summary

This example shows how to:

- Use **BufferedReader/Writer** for simple and efficient file reading/writing in classic IO.
- Use **FileChannel and ByteBuffer** in NIO for lower-level, more performant file operations.
- Handle files safely with automatic resource management.
- Understand when to choose between classic IO (simplicity) and NIO (performance, scalability).

---