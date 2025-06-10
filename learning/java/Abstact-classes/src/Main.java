public class Main {
    public static void main(String[] args) {
        Payment creditCard = new CreditCardPayment(100.0, "1234-5678-9012-3456");
        Payment paypal = new PayPalPayment(75.5, "user@example.com");
        Payment bankTransfer = new BankTransferPayment(200.0, "ACC123456");

        creditCard.processPayment();
        creditCard.printReceipt();

        paypal.processPayment();
        paypal.printReceipt();

        bankTransfer.processPayment();
        bankTransfer.printReceipt();
    }
}