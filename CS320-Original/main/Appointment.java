package main;
import java.util.Date;

public class Appointment {
    private final int ID_MAX_LENGTH = 10;
	private Date appointmentDate;
	private final int DESCRIPTION_MAX_LENGTH = 50;
	private String uniqueID;
	private String appointmentDesc;
    private String initID = "1234567891";
    private String INIT = "INITIALIZER";


    public Appointment() {
        this.uniqueID = initID;
        this.appointmentDesc = INIT;
        this.appointmentDate = new Date();
    }
    public Appointment(String id) {
        setAppointmentID(id);
        this.appointmentDesc = INIT;
        this.appointmentDate = new Date();
    }
    public Appointment(String id, String desc) {
        setAppointmentID(id);
        setAppointmentDesc(desc);
        this.appointmentDate = new Date();
    }
    public Appointment(String id, String desc, Date date) {
        setAppointmentID(id);
        setAppointmentDesc(desc);
        setAppointmentDate(date);
    }

    public void setAppointmentID(String id) throws IllegalArgumentException {
        if (id == null || id.length() > ID_MAX_LENGTH) {
            throw new IllegalArgumentException("Please ensure ID is not empty or greater than 10 characters.");
        }
        this.uniqueID = id;
    }
    public void setAppointmentDesc(String desc) throws IllegalArgumentException {
        if (desc.length() > DESCRIPTION_MAX_LENGTH) {
            throw new IllegalArgumentException("Please ensure Description does not exceed 50 Characters.");
        }
        this.appointmentDesc = desc;
    }
    public void setAppointmentDate(Date date) throws IllegalArgumentException{
        if (date.before(new Date())) {
            throw new IllegalArgumentException("Date must not be in the Past");
        }
        this.appointmentDate = date;
    }

    public String getAppointmentID() {return uniqueID;}
    public String getAppointmentDescription() {return appointmentDesc;}
    public Date getAppointmentDate() {return appointmentDate; }

}
