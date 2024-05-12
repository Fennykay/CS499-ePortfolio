package main;
import java.util.ArrayList;
import java.util.UUID;

public class ContactService {
    ArrayList<Contact> Contacts = new ArrayList<>();
    private String ID;

    private String uniqueID() {
        return ID = UUID.randomUUID().toString().substring(0, Math.min(toString().length(), 10));
    }
    public void newContact() {
        Contact Contact = new Contact(uniqueID());
        Contacts.add(Contact);
    }
    public void newContact(String firstName) {
        Contact Contact = new Contact(uniqueID(), firstName);
        Contacts.add(Contact);
    }
    public void newContact(String firstName, String lastName) {
        Contact Contact = new Contact(uniqueID(), firstName, lastName);
        Contacts.add(Contact);
    }
    public void newContact(String firstName, String lastName, String phoneNum) {
        Contact Contact = new Contact(uniqueID(), firstName, lastName, phoneNum);
        Contacts.add(Contact);
    }
    public void newContact(String firstName, String lastName, String phoneNum, String address) {
        Contact Contact = new Contact(uniqueID(), firstName, lastName, phoneNum, address);
        Contacts.add(Contact);
    }
    public Contact searchContacts(String id) {
        int index = 0;
        while (index < Contacts.size()) {
            if (id.equals(Contacts.get(index).getID())) {
                return Contacts.get(index);
            }
            ++index;
        }
        System.out.println("Contact does not exist.");
        return null;
    }

    public void deleteContact(String id) throws Exception{
        if (searchContacts(id) != null) {
            Contacts.remove(searchContacts(id));
        } else {
            System.out.println("No Contact matching ID");
        }
    }

    public void updateFirstName(String id, String firstName) throws Exception{
        if (searchContacts(id) != null) {
            searchContacts(id).setFirstName(firstName);
        } else {
            System.out.println("No Contact matching ID");
        }
    }
    public void updateLastName(String id, String lastName) throws Exception{
        if (searchContacts(id) != null) {
            searchContacts(id).setLastName(lastName);
        } else {
            System.out.println("No Contact matching ID");
        }
    }
    public void updatePhoneNum(String id, String phoneNum) throws Exception{
        if (searchContacts(id) != null) {
            searchContacts(id).setPhoneNum(phoneNum);
        } else {
            System.out.println("No Contact matching ID");
        }
    }
    public void updateAddress(String id, String Address) throws Exception{
        if (searchContacts(id) != null) {
            searchContacts(id).setAddress(Address);
        } else {
            System.out.println("No Contact matching ID");
        }
    }

    public ArrayList<Contact> getContactList() {return Contacts;}
}
