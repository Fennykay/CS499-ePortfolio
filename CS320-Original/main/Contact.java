package main;

public class Contact {
    private final int ID_MAX_LENGTH = 10;
    private final int NAME_MAX_LENGTH = 10;
    private final int PHONE_NUM_LENGTH = 10;
    private final int ADDRESS_MAX_LENGTH = 30;
    private static final String INIT = "INITIAL";
    private static final String INIT_NUM = "0000000000";
    private String ID;
    private String firstName;
    private String lastName;
    private String phoneNum;
    private String address;

    public Contact(String ID, String firstName, String lastName, String phoneNum, String address) {
        setID(ID);
        setFirstName(firstName);
        setLastName(lastName);
        setPhoneNum(phoneNum);
        setAddress(address);
    }
    public Contact(String ID, String firstName, String lastName, String phoneNum) {
        setID(ID);
        setFirstName(firstName);
        setLastName(lastName);
        setPhoneNum(phoneNum);
        this.address = INIT;
    }
    public Contact(String ID, String firstName, String lastName) {
        setID(ID);
        setFirstName(firstName);
        setLastName(lastName);
        this.phoneNum = INIT_NUM;
        this.address = INIT;
    }
    public Contact(String ID, String firstName) {
        setID(ID);
        setFirstName(firstName);
        this.lastName = INIT;
        this.phoneNum = INIT_NUM;
        this.address = INIT;
    }
    public Contact(String ID) {
        setID(ID);
        this.firstName = INIT;
        this.lastName = INIT;
        this.phoneNum = INIT_NUM;
        this.address = INIT;
    }
    public Contact() {
        this.ID = INIT_NUM;
        this.firstName = INIT;
        this.lastName = INIT;
        this.phoneNum = INIT_NUM;
        this.address = INIT;
    }

    public final String getID() {return ID; }
    public final String getfirstName() {return firstName; }
    public final String getLastName() { return lastName; }
    public final String getPhoneNum() {return phoneNum; }
    public final String getAddress() { return address; }

    protected void setID(String ID) {
        if (ID == null) {
            throw new IllegalArgumentException("ID cannot be empty");
        } else if (ID.length() > ID_MAX_LENGTH) {
            throw new IllegalArgumentException("ID cannot be more than 10 Characters");
        } else {
            this.ID = ID;
        }
    }

    public void setFirstName(String firstName) {
        if (firstName == null) {
            throw new IllegalArgumentException("First Name cannot be empty");
        } else if (firstName.length() > NAME_MAX_LENGTH) {
            throw new IllegalArgumentException("First Name cannot be more than 10 Characters");
        } else {
            this.firstName = firstName;
        }
    }

    public void setLastName(String lastName) {
        if (lastName == null) {
            throw new IllegalArgumentException("Last Name cannot be empty");
        } else if (lastName.length() > NAME_MAX_LENGTH) {
            throw new IllegalArgumentException("Name cannot be more than 10 Characters");
        } else {
            this.lastName = lastName;
        }
    }

    public void setPhoneNum(String phoneNum) {
        String digitCheck = "[0-9]+";
        if (phoneNum == null) {
            throw new IllegalArgumentException("Phone Number cannot be empty");
        } else if (phoneNum.length() != PHONE_NUM_LENGTH) {
            throw new IllegalArgumentException("Phone Number must be 10 Characters");
        } else if (!phoneNum.matches(digitCheck)) {
            throw new IllegalArgumentException("Phone Number can only contain digits.");
        }
        else {
            this.phoneNum = phoneNum;
        }
    }

    public void setAddress(String Address) {
        if (Address == null) {
            throw new IllegalArgumentException("Address cannot be empty");
        } else if (Address.length() > ADDRESS_MAX_LENGTH) {
            throw new IllegalArgumentException("Address cannot be more than 30 Characters");
        } else {
            this.address = Address;
        }
    }
}

