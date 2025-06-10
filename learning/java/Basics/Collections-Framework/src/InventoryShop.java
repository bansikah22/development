import java.util.*;

public class InventoryShop {
    public static void main(String[] args) {
        // List of products
        List<Product> products = new ArrayList<>();
        products.add(new Product("Laptop", "Electronics"));
        products.add(new Product("Chair", "Furniture"));
        products.add(new Product("Phone", "Electronics"));

        // Set to track unique categories
        Set<String> categories = new HashSet<>();
        for (Product p : products) {
            categories.add(p.getCategory());
        }

        // Map for product prices
        Map<String, Double> priceMap = new HashMap<>();
        priceMap.put("Laptop", 1200.0);
        priceMap.put("Chair", 150.0);
        priceMap.put("Phone", 800.0);

        // Queue for restocking requests
        Queue<String> restockQueue = new LinkedList<>();
        restockQueue.add("Laptop");
        restockQueue.add("Chair");

        // Output
        System.out.println("Products:");
        products.forEach(System.out::println);

        System.out.println("\nCategories:");
        categories.forEach(System.out::println);

        System.out.println("\nProduct Prices:");
        priceMap.forEach((k, v) -> System.out.println(k + ": $" + v));

        System.out.println("\nProcessing Restock Queue:");
        while (!restockQueue.isEmpty()) {
            String item = restockQueue.poll();
            System.out.println("Restocking " + item);
        }
    }
}