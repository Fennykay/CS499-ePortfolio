package test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import main.Appointment;
import main.AppointmentService;

import java.sql.Date;
import java.util.ArrayList;

public class AppointmentServiceTest {
    private AppointmentService appointmentService;
    private Date futureDate;

    @BeforeEach
    public void setUp() {
        appointmentService = new AppointmentService();
        futureDate = new Date(2023, 12, 1);

    }

    @Test
    public void testCreateAppointment() {
        // Test initialization of Appointment
        appointmentService.createAppointment();
        ArrayList<Appointment> appointmentList = appointmentService.getAppointmentList();
        Assertions.assertEquals(1, appointmentList.size());
    }

    @Test
    public void testCreateAppointmentWithDescription() {
        // create Appointment with a custom Description
        appointmentService.createAppointment("Appointment with description");
        ArrayList<Appointment> appointmentList = appointmentService.getAppointmentList();
        Assertions.assertEquals(1, appointmentList.size());
        Appointment appointment = appointmentList.get(0);
        Assertions.assertEquals("Appointment with description", appointment.getAppointmentDescription());
    }

    @Test
    public void testCreateAppointmentWithDescriptionAndDate() {
        // create Appointment with custom date and description
        appointmentService.createAppointment("Appointment with description and date", futureDate);
        ArrayList<Appointment> appointmentList = appointmentService.getAppointmentList();
        Assertions.assertEquals(1, appointmentList.size());
        Appointment appointment = appointmentList.get(0);
        Assertions.assertEquals("Appointment with description and date", appointment.getAppointmentDescription());
        Assertions.assertEquals(futureDate, appointment.getAppointmentDate());
    }

    @Test
    public void testSearchAppointment() throws Exception {
        // list filling
        appointmentService.createAppointment("Appointment 1", futureDate);
        appointmentService.createAppointment("Appointment 2", futureDate);
        appointmentService.createAppointment("Appointment 3", futureDate);

        // calling search function
        String searchID = appointmentService.getAppointmentList().get(2).getAppointmentID();
        Appointment appointment = appointmentService.searchAppointment(searchID);
        Assertions.assertNotNull(appointment);
        Assertions.assertEquals(searchID, appointment.getAppointmentID());
    }

    @Test
    public void testDeleteAppointment() throws Exception {
        Date futureDate = new Date(2023, 12, 1);
        appointmentService.createAppointment("Appointment to delete", futureDate);

        String deleteID = appointmentService.getAppointmentList().get(0).getAppointmentID();
        ArrayList<Appointment> appointmentListBefore = appointmentService.getAppointmentList();
        Assertions.assertEquals(1, appointmentListBefore.size());

        appointmentService.deleteAppointment(deleteID);

        ArrayList<Appointment> appointmentListAfter = appointmentService.getAppointmentList();
        Assertions.assertEquals(0, appointmentListAfter.size());
    }
}
