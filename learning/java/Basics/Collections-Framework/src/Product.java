public class Product {
    String name;
    String category;

    public Product(String name, String category){
        this.name = name;
        this.category = category;
    }

    public String getName(){
        return name;
    }

    public String getCategory(){
        return category;
    }

    @Override
    public String toString() {
        return name + " (" + category + ")";
    }
}
