#ifndef CONTACT_H
#define CONTACT_H

#include <string>


using std::string;

const size_t MAX_NAME_LENGTH = 50;
const size_t MAX_PHONE_NUMBER_LENGTH = 15;
const size_t MAX_EMAIL_LENGTH = 50;
const size_t MAX_STREET_ADDRESS_LENGTH = 100;

class Contact {
public:
    Contact(
        string name = "",
        string phoneNumber = "",
        string email = "",
        string streetAddress = "",
        string city = "",
        string state = "",
        string zipCode = "",
        string country = "",
        string notes = ""
        );

    void setName(string name);
    string getName() const;

    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber() const;

    void setEmail(string email);
    string getEmail() const;

    void setStreetAddress(string streetAddress);
    string getStreetAddress() const;

    void setCity(string city);
    string getCity() const;

    void setState(string state);
    string getState() const;

    void setZipCode(string zipCode);
    string getZipCode() const;

    void setCountry(string country);
    string getCountry() const;

    void setNotes(string notes);
    string getNotes() const;

    int getID() const;

private:
    int ID;
    string name;
    string phoneNumber;
    string email;
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
    string notes;
};



#endif // CONTACT_H
