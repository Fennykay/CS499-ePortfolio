package test;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertThrows;
import static org.junit.jupiter.api.Assertions.assertAll;

import org.junit.Assert;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import main.ContactService;


public class ContactServiceTest {
    // initialize set of correct variables
    protected String id, firstName, lastName, phoneNum, address;
    // initialize set of incorrect variables
    protected String longID, longFirstName, longLastName, longPhoneNum, longAddress;
    // initializers for contact class
    protected String INIT, INIT_NUM;

    @BeforeEach
    void setUp() {
        id = "1a2b3c4d5e";
        firstName = "Kenny";
        lastName = "Fancher";
        phoneNum = "1234567891";
        address = "7851 Flowerfield Road";

        longID = "1a2b3c4d5e6g7h8i";
        longFirstName = "RandomRandomLong";
        longLastName = "Random random longer";
        longPhoneNum = "1800283884388352";
        longAddress = " Random Random Random Random Random Random Random Random Random";

        INIT = "INITIAL";
        INIT_NUM = "0000000000";
    }

    @Test
    public void newContactTest() {
        ContactService service = new ContactService();
        service.newContact();
        //test constructor
        assertAll("service",
        ()
            -> assertNotNull(service.getContactList().get(0).getID()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(0).getfirstName()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(0).getLastName()),
        ()
            -> Assert.assertEquals(INIT_NUM, service.getContactList().get(0).getPhoneNum()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(0).getAddress()));
        // testing firstname constructor
        service.newContact(firstName);
        assertAll("service",
        ()
            -> assertNotNull(service.getContactList().get(1).getID()),
        ()
            -> Assert.assertEquals(firstName, service.getContactList().get(1).getfirstName()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(1).getLastName()),
        ()
            -> Assert.assertEquals(INIT_NUM, service.getContactList().get(1).getPhoneNum()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(1).getAddress()));
        // testing firstName+lastName
        service.newContact(firstName, lastName);
        assertAll("service",
        ()
            -> assertNotNull(service.getContactList().get(2).getID()),
        ()
            -> Assert.assertEquals(firstName, service.getContactList().get(2).getfirstName()),
        ()
            -> Assert.assertEquals(lastName, service.getContactList().get(2).getLastName()),
        ()
            -> Assert.assertEquals(INIT_NUM, service.getContactList().get(2).getPhoneNum()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(2).getAddress()));  
        // testing firstName, lastName, phoneNum
        service.newContact(firstName, lastName, phoneNum);
        assertAll("service",
        ()
            -> assertNotNull(service.getContactList().get(3).getID()),
        ()
            -> Assert.assertEquals(firstName, service.getContactList().get(3).getfirstName()),
        ()
            -> Assert.assertEquals(lastName, service.getContactList().get(3).getLastName()),
        ()
            -> Assert.assertEquals(phoneNum, service.getContactList().get(3).getPhoneNum()),
        ()
            -> Assert.assertEquals(INIT, service.getContactList().get(3).getAddress()));

        service.newContact(firstName, lastName, phoneNum, address);
        assertAll("service",
        ()
            -> assertNotNull(service.getContactList().get(4).getID()),
        ()
            -> Assert.assertEquals(firstName, service.getContactList().get(4).getfirstName()),
        ()
            -> Assert.assertEquals(lastName, service.getContactList().get(4).getLastName()),
        ()
            -> Assert.assertEquals(phoneNum, service.getContactList().get(4).getPhoneNum()),
        ()
            -> Assert.assertEquals(address, service.getContactList().get(4).getAddress()));
    }

    @Test
    public void deleteContactTest() {
        ContactService service = new ContactService();
        service.newContact();

        assertAll(()
            -> service.deleteContact(service.getContactList().get(0).getID()));
        Assert.assertEquals(0, service.getContactList().size());

        assertThrows(Exception.class, ()
            -> service.deleteContact(service.getContactList().get(0).getID()));
    }
}
