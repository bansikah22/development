
public class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public void printProductInfo() {
        System.out.println("Product: " + name + ", Price: $" + price);
    }
}
