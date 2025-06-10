package learning.java.threads;
public class MultiThread {
    public static void main(String[] args) {


       for (int i = 0; i < 3; i++) {
        MultithreadThing thing = new MultithreadThing(i);
        Thread thread = new Thread(thing);
        thread.start();
       // the .join() method is used to wait for the thread to finish executing before moving on to the next line of code.
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // thing.isAlive(); used when we want to check if a thread is still running
        // thread.isDaemon(); used when we want to mark a thread as a daemon thread.

       }
       throw new RuntimeException();
    }
}
