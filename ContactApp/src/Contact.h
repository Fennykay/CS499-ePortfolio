#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact {
public:
    // Constructors
    Contact();
    Contact(string name);
    Contact(string name, string phoneNumber);
    Contact(string name, string phoneNumber, string email);
    Contact(string name, string phoneNumber, string email, string streetAddress);
    Contact(string name, string phoneNumber, string email, string streetAddress, string city);
    Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state);
    Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state, string zipCode);
    Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state, string zipCode, string country);
    Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state, string zipCode, string country, string notes);
    // Getters and Setters
    void setName(string name);
    string getName() const;

    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber()const;

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

    const int MAX_NAME_LENGTH = 15;
    const int MAX_PHONE_NUMBER_LENGTH = 12;
    const int MAX_EMAIL_LENGTH = 15;
    const int MAX_STREET_ADDRESS_LENGTH = 30;

};



#endif // CONTACT_H
