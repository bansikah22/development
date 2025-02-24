public class Car extends Vehicle {
    int doors;
    String color;

    public Car(double speed, int doors, String color) {
        super(speed); // Calls the new Vehicle constructor
        this.doors = doors;
        this.color = color;
    }

    public int getDoors() {
        return doors;
    }

    public void setDoors(int doors) {
        this.doors = doors;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Car{speed=" + speed + ", doors=" + doors + ", color='" + color + "'}";
    }
}
