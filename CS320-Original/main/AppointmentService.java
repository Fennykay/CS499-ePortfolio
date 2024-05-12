package main;
import java.util.UUID;
import java.sql.Date;
import java.util.ArrayList;

public class AppointmentService {
    private final ArrayList<Appointment> appointmentList = new ArrayList<>();
    private String generateID() {
        return UUID.randomUUID().toString().substring(0, Math.min(toString().length(), 10));
    }
    public void createAppointment() {
        Appointment appointment = new Appointment(generateID());
        appointmentList.add(appointment);
    }
    public void createAppointment(String description) {
        Appointment appointment = new Appointment(generateID(), description);
        appointmentList.add(appointment);
    }
    public void createAppointment(String description, Date date) {
        Appointment appointment = new Appointment(generateID(), description, date);
        appointmentList.add(appointment);
    }

    public Appointment searchAppointment(String id) throws Exception {
        int index = 0;

        while (index < appointmentList.size()) {
            if (id.equals(appointmentList.get(index).getAppointmentID())) {
                return appointmentList.get(index);
            }
            ++index;
        }
        throw new Exception("Task not found");
    }

    public void deleteAppointment(String id) throws Exception {
        appointmentList.remove(searchAppointment(id));
    }

    public ArrayList<Appointment> getAppointmentList() {return appointmentList;}
}
