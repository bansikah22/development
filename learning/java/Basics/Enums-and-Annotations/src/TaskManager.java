import java.lang.reflect.Method;

public class TaskManager {
    private boolean isAdmin;

    public TaskManager(boolean isAdmin) {
        this.isAdmin = isAdmin;
    }

    public void updateTaskStatus(Task task, TaskStatus newStatus) throws Exception {
        if (!checkAdminPrivileges("updateTaskStatus")) {
            throw new SecurityException("Admin privileges required to update task status.");
        }
        task.setStatus(newStatus);
        System.out.println("Task '" + task.getName() + "' status updated to " + newStatus);
    }

    @RequiresAdmin
    public void deleteTask(Task task) {
        System.out.println("Task '" + task.getName() + "' deleted.");
    }

    private boolean checkAdminPrivileges(String methodName) throws Exception {
        Method method = this.getClass().getMethod(methodName, Task.class);
        if (method.isAnnotationPresent(RequiresAdmin.class)) {
            return isAdmin;
        }
        return true; // No annotation means no admin check required
    }
}