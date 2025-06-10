public class Main {
    public static void main(String[] args) {
        Task task1 = new Task("Write report", TaskStatus.TODO);
        TaskManager adminManager = new TaskManager(true);
        TaskManager userManager = new TaskManager(false);

        try {
            // Admin can update status
            adminManager.updateTaskStatus(task1, TaskStatus.IN_PROGRESS);

            // Non-admin tries to update status (should throw exception)
            userManager.updateTaskStatus(task1, TaskStatus.COMPLETED);
        } catch (SecurityException se) {
            System.out.println("SecurityException: " + se.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Admin deletes task
        adminManager.deleteTask(task1);

        // Output the final status
        System.out.println("Final status of task '" + task1.getName() + "': " + task1.getStatus());
    }
}