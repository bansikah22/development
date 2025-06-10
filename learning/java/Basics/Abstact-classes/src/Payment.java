public abstract class Payment {
    protected double amount;

    public Payment(double amount) {
        this.amount = amount;
    }

    // Abstract method to be implemented by subclasses
    public abstract void processPayment();

    // Concrete method shared by all payment types
    public void printReceipt() {
        System.out.println("Payment of $" + amount + " processed.");
    }
}