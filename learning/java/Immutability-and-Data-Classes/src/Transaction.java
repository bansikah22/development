import java.time.LocalDateTime;
import java.util.UUID;

public final class Transaction {

    private final String transactionId;
    private final double amount;
    private final LocalDateTime timestamp;
    private final String sender;
    private final String receiver;

    public Transaction(double amount, String sender, String receiver) {
        this.transactionId = UUID.randomUUID().toString();
        this.amount = amount;
        this.timestamp = LocalDateTime.now();
        this.sender = sender;
        this.receiver = receiver;
    }

    public String getTransactionId() {
        return transactionId;
    }

    public double getAmount() {
        return amount;
    }

    public LocalDateTime getTimestamp() {
        return timestamp;
    }

    public String getSender() {
        return sender;
    }

    public String getReceiver() {
        return receiver;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "transactionId='" + transactionId + '\'' +
                ", amount=" + amount +
                ", timestamp=" + timestamp +
                ", sender='" + sender + '\'' +
                ", receiver='" + receiver + '\'' +
                '}';
    }
}