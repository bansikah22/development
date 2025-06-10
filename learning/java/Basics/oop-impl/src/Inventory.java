import java.util.ArrayList;

public class Inventory {
    private ArrayList<Item> items;

    public Inventory() {
        items = new ArrayList<>();
    }

    public void addItem(Item item){
        items.add(item);
    }

    public void displayInventory(){
        for (Item item : items){
//            System.out.println("Item Name: " + item.getName() + " Quantity: " + item.getQuantity());
            System.out.println("Item" + item.toString());
        }
    }
}