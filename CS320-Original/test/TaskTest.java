package test;

import org.junit.jupiter.api.Test;

import main.Task;

import static org.junit.jupiter.api.Assertions.*;

public class TaskTest {
    @Test
    public void testTask() {
        Task task = new Task();
        assertEquals("123456789", task.getTaskID());
        assertEquals("Initialize", task.getTaskName());
        assertEquals("Initialize", task.getTaskDescription());
    }

    @Test
    public void testTaskID() {
        String taskID = "T123";
        Task task = new Task(taskID);
        assertEquals(taskID, task.getTaskID());
        assertEquals("Initialize", task.getTaskName());
        assertEquals("Initialize", task.getTaskDescription());
    }

    @Test
    public void testTaskIDAndName() {
        String taskID = "T123";
        String taskName = "Sample Task";
        Task task = new Task(taskID, taskName);
        assertEquals(taskID, task.getTaskID());
        assertEquals(taskName, task.getTaskName());
        assertEquals("Initialize", task.getTaskDescription());
    }

    @Test
    public void testTaskIDNameAndDescription() {
        String taskID = "T123";
        String taskName = "Sample Task";
        String taskDesc = "This is a sample task";
        Task task = new Task(taskID, taskName, taskDesc);
        assertEquals(taskID, task.getTaskID());
        assertEquals(taskName, task.getTaskName());
        assertEquals(taskDesc, task.getTaskDescription());
    }

    @Test
    public void testSetTaskName() {
        Task task = new Task();
        String taskName = "Updated Task Name";
        task.setTaskName(taskName);
        assertEquals(taskName, task.getTaskName());
    }

    @Test
    public void testSetTaskNameLongLength() {
        Task task = new Task();
        String taskName = "Veeeeeeerrrrrrry Loooooooooong Taaaaaaaaaask Naaaaaaaaaaaaaaaaame";
        assertThrows(IllegalArgumentException.class, () -> task.setTaskName(taskName));
    }

    @Test
    public void testSetTaskDescription() {
        Task task = new Task();
        String taskDesc = "Updated Task Description";
        task.setTaskDescription(taskDesc);
        assertEquals(taskDesc, task.getTaskDescription());
    }

    @Test
    public void testSetTaskDescriptionLongLength() {
        Task task = new Task();
        String taskDesc = "Verrrrrrryyyyyyyyyyyyyy Looooooooooooooooonnnngggggggggggggggggggggggggggg Description";
        assertThrows(IllegalArgumentException.class, () -> task.setTaskDescription(taskDesc));
    }

    @Test
    public void testSetTaskID() {
        Task task = new Task();
        String taskID = "T999";
        task.setTaskID(taskID);
        assertEquals(taskID, task.getTaskID());
    }

    @Test
    public void testSetTaskIDLongLength() {
        Task task = new Task();
        String taskID = "T1234567890";
        assertThrows(IllegalArgumentException.class, () -> task.setTaskID(taskID));
    }

}
