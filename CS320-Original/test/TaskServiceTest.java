package test;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import main.Task;
import main.TaskService;

import static org.junit.jupiter.api.Assertions.*;

public class TaskServiceTest {
    private TaskService taskService;

    @BeforeEach
    public void setUp() {
        taskService = new TaskService();
    }

    @Test
    public void testCreateTask() {
        taskService.createTask();
        assertEquals(1, taskService.getTaskList().size());
    }

    @Test
    public void testCreateTaskWithName() {
        String taskName = "Sample Task";
        taskService.createTask(taskName);
        assertEquals(1, taskService.getTaskList().size());
        assertEquals(taskName, taskService.getTaskList().get(0).getTaskName());
    }

    @Test
    public void testCreateTaskWithNameAndDescription() {
        String taskName = "Sample Task";
        String taskDesc = "This is a sample task";
        taskService.createTask(taskName, taskDesc);
        assertEquals(1, taskService.getTaskList().size());
        assertEquals(taskName, taskService.getTaskList().get(0).getTaskName());
        assertEquals(taskDesc, taskService.getTaskList().get(0).getTaskDescription());
    }

    @Test
    public void testDeleteTask() throws Exception {
        taskService.createTask();
        Task task = taskService.getTaskList().get(0);
        String taskID = task.getTaskID();
        taskService.deleteTask(taskID);
        assertTrue(taskService.getTaskList().isEmpty());
    }

    @Test
    public void testUpdateTaskName() throws Exception {
        taskService.createTask();
        Task task = taskService.getTaskList().get(0);
        String taskID = task.getTaskID();
        String newTaskName = "New Task Name";
        taskService.updateTaskName(taskID, newTaskName);
        assertEquals(newTaskName, task.getTaskName());
    }

    @Test
    public void testUpdateTaskDescription() throws Exception {
        taskService.createTask();
        Task task = taskService.getTaskList().get(0);
        String taskID = task.getTaskID();
        String newTaskDesc = "New Task Description";
        taskService.updateTaskDescription(taskID, newTaskDesc);
        assertEquals(newTaskDesc, task.getTaskDescription());
    }
}
