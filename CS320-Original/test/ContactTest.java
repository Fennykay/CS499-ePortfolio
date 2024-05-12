package test;
import static org.junit.Assert.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertAll;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import main.Contact;


public class ContactTest {
    private Contact contact;

    @Before
    public void setup() {
        contact = new Contact("1", "John", "Doe", "9097442720", "7851 Flowerfield Road");
    }

    @Test
    public void constructorTest() {
        Contact contact2 = new Contact();

        assertAll("constructor", 
            ()
                -> assertNotNull(contact2.getID()),
            ()
                -> assertNotNull(contact2.getfirstName()),
            ()
                -> assertNotNull(contact2.getLastName()),
            ()
                -> assertNotNull(contact2.getPhoneNum()),
            ()
                -> assertNotNull(contact2.getPhoneNum()));
    }

    @Test
    public void constructorIDTest() {
        String id = "1a2b3c4d5e";
        Contact contact2 = new Contact(id);

        assertAll("constructor", 
            ()
                -> Assert.assertEquals(id,contact2.getID()),
            ()
                -> assertNotNull(contact2.getfirstName()),
            ()
                -> assertNotNull(contact2.getLastName()),
            ()
                -> assertNotNull(contact2.getPhoneNum()),
            ()
                -> assertNotNull(contact2.getPhoneNum()));
    }

    @Test
    public void constructorIDFirstNameTest() {
        String id = "1a2b3c4d5e";
        String firstName = "Kenneth";
        Contact contact2 = new Contact(id, firstName);

        assertAll("constructor", 
            ()
                -> Assert.assertEquals(id,contact2.getID()),
            ()
                -> Assert.assertEquals(firstName,contact2.getfirstName()),
            ()
                -> assertNotNull(contact2.getLastName()),
            ()
                -> assertNotNull(contact2.getPhoneNum()),
            ()
                -> assertNotNull(contact2.getPhoneNum()));
    }

    @Test
    public void constructorIDFirstNameLastNameTest() {
        String id = "1a2b3c4d5e";
        String firstName = "Kenneth";
        String lastName = "Fancher";
        Contact contact2 = new Contact(id, firstName, lastName);

        assertAll("constructor", 
            ()
                -> Assert.assertEquals(id,contact2.getID()),
            ()
                -> Assert.assertEquals(firstName,contact2.getfirstName()),
            ()
                -> Assert.assertEquals(lastName,contact2.getLastName()),
            ()
                -> assertNotNull(contact2.getPhoneNum()),
            ()
                -> assertNotNull(contact2.getPhoneNum()));
    }

    @Test
    public void constructorIDFirstNameLastNamePhoneNumTest() {
        String id = "1a2b3c4d5e";
        String firstName = "Kenneth";
        String lastName = "Fancher";
        String phoneNum = "1800888343";
        Contact contact2 = new Contact(id, firstName, lastName, phoneNum);

        assertAll("constructor", 
            ()
                -> Assert.assertEquals(id,contact2.getID()),
            ()
                -> Assert.assertEquals(firstName,contact2.getfirstName()),
            ()
                -> Assert.assertEquals(lastName,contact2.getLastName()),
            ()
                -> Assert.assertEquals(phoneNum,contact2.getPhoneNum()),
            ()
                -> assertNotNull(contact2.getPhoneNum()));
    }

    @Test
    public void constructorAllTest() {
        String id = "1a2b3c4d5e";
        String firstName = "Kenneth";
        String lastName = "Fancher";
        String phoneNum = "1800888343";
        String address = "7851 Flowerfield road, APT 301";
        Contact contact2 = new Contact(id, firstName, lastName, phoneNum,address);

        assertAll("constructor", 
            ()
                -> Assert.assertEquals(id,contact2.getID()),
            ()
                -> Assert.assertEquals(firstName,contact2.getfirstName()),
            ()
                -> Assert.assertEquals(lastName,contact2.getLastName()),
            ()
                -> Assert.assertEquals(phoneNum,contact2.getPhoneNum()),
            ()
                -> Assert.assertEquals(address,contact2.getAddress()));
    }

    @Test
    public void testGetFirstName() {
        String firstName = contact.getfirstName();

        Assert.assertEquals("John", firstName);
    }

    @Test
    public void testGetLastName() {
        String lastName = contact.getLastName();    

        Assert.assertEquals("Doe", lastName);
    }

    @Test
    public void testGetPhoneNum() {
        String phoneNum = contact.getPhoneNum();

        Assert.assertEquals("9097442720", phoneNum);
    }

    @Test
    public void testGetAddress() {
        String address = contact.getAddress();

        Assert.assertEquals("7851 Flowerfield Road", address);
    }
    @Test
    public void testGetID() {
        String id = contact.getID();

        Assert.assertEquals("1", id);
    }

    @Test
    public void testSetFirstName() {
        contact.setFirstName("Kenneth");

        Assert.assertEquals("Kenneth", contact.getfirstName());
    }
    @Test
    public void testSetLastName() {
        // Test setting a correct name
        contact.setLastName("Fancher");
        Assert.assertEquals("Fancher", contact.getLastName());

        // Test setting a too long name
        String expectedMessage = "Name cannot be more than 10 Characters";

        Exception exception = Assert.assertThrows(IllegalArgumentException.class, () -> {
            contact.setLastName("Looooooooooong Name, too long.");
        });

        String actualErrorMessage = exception.getMessage();
        Assert.assertEquals(expectedMessage, actualErrorMessage);
    }

    @Test
    public void testSetAddress() {
        // Test setting a new address
        contact.setAddress("random street address");

        Assert.assertEquals("random street address", contact.getAddress());

        // Test setting too long address

        String expectedMessage = "Address cannot be more than 30 Characters";

        Exception exception = Assert.assertThrows(IllegalArgumentException.class, () -> {
            contact.setAddress("realllllyyyyyyyyyyyyy loooooooooonggggggggggg adddressssssssssssssssssssss");
        });

        String actualErrorMessage = exception.getMessage();
        Assert.assertEquals(expectedMessage, actualErrorMessage);
    }

    @Test
    public void testSetPhoneNum() {
        // Test setting new phone num
        contact.setPhoneNum("8008675309");

        Assert.assertEquals("8008675309", contact.getPhoneNum());

        // Test setting phoneNum that is not 10 characters
        String expectedLengthMessage = "Phone Number must be 10 Characters";

        Exception exceptionLength = Assert.assertThrows(IllegalArgumentException.class, () -> {
            contact.setPhoneNum("1800");
        });

        String actualLengthErrorMessage = exceptionLength.getMessage();
        Assert.assertEquals(expectedLengthMessage, actualLengthErrorMessage);

        // Test setting phoneNum with Letters
        String expectedDigitMessage = "Phone Number can only contain digits.";

        Exception exceptionDigit = Assert.assertThrows(IllegalArgumentException.class, () -> {
            contact.setPhoneNum("8949sa9010");
        });

        String actualDigitErrorMessage = exceptionDigit.getMessage();
        Assert.assertEquals(expectedDigitMessage, actualDigitErrorMessage);
    }


}
