package test;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import main.Appointment;

import java.util.Date;

public class AppointmentTest {
    private Date futureDate;
    private String AppointmentDesc;
    private String longDescription;

    @BeforeEach
    public void setUp() {
        futureDate = new Date(2023, 12, 31);
        AppointmentDesc = "Appointment Description";
        longDescription = "This is a very loooooooooooooooooooooooooooooooooong Description that is way too long";

    }
    @Test
    public void testSetAppointmentID() {
        Appointment appointment = new Appointment();

        // Valid ID
        appointment.setAppointmentID("1234567890");
        Assertions.assertEquals("1234567890", appointment.getAppointmentID());

        // Null ID
        Assertions.assertThrows(IllegalArgumentException.class, () -> appointment.setAppointmentID(null));

        // ID exceeding max length
        Assertions.assertThrows(IllegalArgumentException.class, () -> appointment.setAppointmentID("12345678901"));
    }

    @Test
    public void testSetAppointmentDesc() {
        Appointment appointment = new Appointment();

        // Valid description
        appointment.setAppointmentDesc(AppointmentDesc);
        Assertions.assertEquals(AppointmentDesc, appointment.getAppointmentDescription());

        // Description exceeding max length
        Assertions.assertThrows(IllegalArgumentException.class, () -> appointment.setAppointmentDesc(longDescription));
    }

    @Test
    public void testSetAppointmentDate() {
        Appointment appointment = new Appointment();

        // Valid date
        appointment.setAppointmentDate(futureDate);
        Assertions.assertEquals(futureDate, appointment.getAppointmentDate());

        // invalid date
        Date pastDate = new Date(System.currentTimeMillis() - 24 * 60 * 60 * 1000); // Yesterday
        Assertions.assertThrows(IllegalArgumentException.class, () -> appointment.setAppointmentDate(pastDate));
    }

}
