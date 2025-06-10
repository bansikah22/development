public class Task {
    private String name;
    private TaskStatus status;

    public Task(String name, TaskStatus status) {
        this.name = name;
        this.status = status;
    }

    public void setStatus(TaskStatus status) {
        this.status = status;
    }

    public TaskStatus getStatus() {
        return status;
    }

    public String getName() {
        return name;
    }
}