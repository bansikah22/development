// inheritance in application
public class Fruit extends Item { // 'Fruit' inherits from 'Item' class, allowing it to use 'Item's properties and methods
    private String type;

    //custom custructore for Fruit class
   public Fruit(String name, int quantity, String type) {
       super(name, quantity); // Call the constructor of the superclass 'Item' to initialize 'name' and 'quantity'
       this.type = type; // Assign the parameter 'type' to the instance variable 'type'
   }

   public String getType() {
       return type;
   }
   public void setType(String type) {
       this.type = type;
   }

   @Override
   public String toString() {
       return "Fruit: " + type + " " + super.toString();
   }
}