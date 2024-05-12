package main;

public class Task {
    private final int maxTaskID_Length = 10;
    private final int maxTaskName_Length = 20;
    private final int maxDescription_Length = 50;
    private final String INIT = "Initialize";
    private final String INIT_NUM = "123456789";
    private String taskID;
    private String name;
    private String description;

    public Task() {
        taskID = INIT_NUM;
        name = INIT;
        description = INIT;
    }

    public Task(String ID) {
        setTaskID(ID);
        name = INIT;
        description = INIT;
    }
    public Task(String ID, String taskName) {
        setTaskID(ID);
        setTaskName(taskName);
        description = INIT;     
    }
    public Task(String ID, String taskName, String taskDesc) {
        setTaskID(ID);
        setTaskName(taskName);
        setTaskDescription(taskDesc);
    }

    public void setTaskName(String taskName) {
        if (taskName.length() > maxTaskName_Length) {
            throw new IllegalArgumentException("The Task Name cannot be longer than 20 Characters");
        } else {
            this.name = taskName;
        }
    }
    public void setTaskDescription(String taskDesc) {
        if (taskDesc.length() > maxDescription_Length) {
            throw new IllegalArgumentException("The Task Description cannot exceed 50 Characters");

        } else {
            this.description = taskDesc;
        }
    }
    public void setTaskID(String uniqueID) {
        if (uniqueID.length() > maxTaskID_Length || uniqueID == null) {
            throw new IllegalArgumentException("Please ensure the ID is not Null or longer than " + maxTaskID_Length);
        } else {
            this.taskID = uniqueID;
        }
    }

    public final String getTaskID() {return taskID; }

    public final String getTaskName() {return name;}

    public final String getTaskDescription() {return description;}

}
