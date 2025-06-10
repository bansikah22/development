public class Main {
    public static void main(String[] args) {
        Car car1 = new Car(120.0, 4, "Blue");
        car1.go();
        System.out.println(car1);

        Bicycle bike = new Bicycle(8.5, 2); // Pass both speed and pedals
        bike.go();
        System.out.println(bike);

        AirPlane plane = new AirPlane(500.0, 2);
        plane.go();
        System.out.println(plane);
    }
}

