public class Main {
    public static void main(String[] args) {
        // Store User
        DataStorage<User> userStorage = new DataStorage<>();
        User user = new User("Alice", 30);
        userStorage.setData(user);
        userStorage.getData().printUserInfo();

        // Store Product
        DataStorage<Product> productStorage = new DataStorage<>();
        Product product = new Product("Laptop", 1200.50);
        productStorage.setData(product);
        productStorage.getData().printProductInfo();
    }
}
