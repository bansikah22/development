public class AirPlane extends Vehicle {
    int wings;

    public AirPlane(double speed, int wings) {
        super(speed); // Pass speed to Vehicle constructor
        this.wings = wings;
    }

    public int getWings() {
        return wings;
    }

    public void setWings(int wings) {
        this.wings = wings;
    }

    @Override
    public String toString() {
        return "AirPlane{speed=" + speed + ", wings=" + wings + "}";
    }
}
