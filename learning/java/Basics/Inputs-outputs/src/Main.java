public class Main {
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