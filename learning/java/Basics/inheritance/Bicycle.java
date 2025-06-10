public class Bicycle extends Vehicle {
    int pedals;

    public Bicycle(double speed, int pedals) {
        super(speed);
        this.pedals = pedals;
    }

    public int getPedals() {
        return pedals;
    }

    public void setPedals(int pedals) {
        this.pedals = pedals;
    }

    @Override
    public String toString() {
        return "Bicycle{speed=" + speed + ", pedals=" + pedals + "}";
    }
}
