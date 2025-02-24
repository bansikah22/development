public class Vehicle {
    double speed;

    public Vehicle(double speed) { // Added constructor
        this.speed = speed;
    }

    void go() {
        System.out.println("The vehicle is moving at speed: " + speed);
    }

    void stop() {
        System.out.println("The vehicle has stopped.");
    }
}
