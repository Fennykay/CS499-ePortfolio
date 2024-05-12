package main;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class TaskService {
    private final List<Task> taskList = new ArrayList<>();

    private String uniqueID() {
        return UUID.randomUUID().toString().substring(0, Math.min(toString().length(), 10));
    }

    public void createTask() {
        Task task = new Task(uniqueID());
        taskList.add(task);
    }
    public void createTask(String taskName) {
        Task task = new Task(uniqueID(), taskName);
        taskList.add(task);
    }
    public void createTask(String taskName, String taskDesc) {
        Task task = new Task(uniqueID(), taskName, taskDesc);
        taskList.add(task);
    }

    private Task searchTask(String ID) throws Exception {
        int index = 0;

        while (index < taskList.size()) {
            if (ID.equals(taskList.get(index).getTaskID())) {
                return taskList.get(index);
            }
            ++index;
        }
        throw new Exception("Task not found");
    }
    public void deleteTask(String ID) throws Exception{
        taskList.remove(searchTask(ID));
    }
    public void updateTaskName(String ID, String taskName) throws Exception {
        searchTask(ID).setTaskName(taskName);
    }
    public void updateTaskDescription(String ID, String description) throws Exception{
        searchTask(ID).setTaskDescription(description);
    }

    public List<Task> getTaskList() {return taskList;}
}
