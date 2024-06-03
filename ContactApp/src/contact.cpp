#include "Contact.h"

Contact::Contact() {
    setName("");
    setPhoneNumber("");
    setEmail("");
    setStreetAddress("");
    setCity("");
    setState("");
    setZipCode("");
    setCountry("");
    setNotes("");

}

Contact::Contact(string name) {
    setName(name);
    setPhoneNumber("");
    setEmail("");
    setStreetAddress("");
    setCity("");
    setState("");
    setZipCode("");
    setCountry("");
    setNotes("");

}

Contact::Contact(string name, string phoneNumber) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail("");
    setStreetAddress("");
    setCity("");
    setState("");
    setZipCode("");
    setCountry("");
    setNotes("");

}

Contact::Contact(string name, string phoneNumber, string email) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress("");
    setCity("");
    setState("");
    setZipCode("");
    setCountry("");
    setNotes("");

}


Contact::Contact(string name, string phoneNumber, string email, string streetAddress) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress(streetAddress);
    setCity("");
    setState("");
    setZipCode("");
    setCountry("");
    setNotes("");

}

Contact::Contact(string name, string phoneNumber, string email, string streetAddress, string city) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress(streetAddress);
    setCity(city);
    setState("");
    setZipCode("");
    setCountry("");
    setNotes("");

}

Contact::Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress(streetAddress);
    setCity(city);
    setState(state);
    setZipCode("");
    setCountry("");
    setNotes("");
}

Contact::Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state, string zipCode) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress(streetAddress);
    setCity(city);
    setState(state);
    setZipCode(zipCode);
    setCountry("");
    setNotes("");

}

Contact::Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state, string zipCode, string country) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress(streetAddress);
    setCity(city);
    setState(state);
    setZipCode(zipCode);
    setCountry(country);
    setNotes("");

}

Contact::Contact(string name, string phoneNumber, string email, string streetAddress, string city, string state, string zipCode, string country, string notes) {
    setName(name);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStreetAddress(streetAddress);
    setCity(city);
    setState(state);
    setZipCode(zipCode);
    setCountry(country);
    setNotes(notes);

}

void Contact::setName(string name) {
    if (name.length() > MAX_NAME_LENGTH) {
        this->name = name.substr(0, MAX_NAME_LENGTH);
    } else {
        this->name = name;
    }
}

string Contact::getName() const {
    return name;
}

void Contact::setPhoneNumber(string phoneNumber) {
    if (phoneNumber.length() > MAX_PHONE_NUMBER_LENGTH) {
        this->phoneNumber = phoneNumber.substr(0, MAX_PHONE_NUMBER_LENGTH);
    } else {
        this->phoneNumber = phoneNumber;
    }
}

string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::setEmail(string email) {
    if (email.length() > MAX_EMAIL_LENGTH) {
        this->email = email.substr(0, MAX_EMAIL_LENGTH);
    } else {
        this->email = email;
    }
}

string Contact::getEmail() const {
    return email;
}

void Contact::setStreetAddress(string streetAddress) {
    if (streetAddress.length() > MAX_STREET_ADDRESS_LENGTH) {
        this->streetAddress = streetAddress.substr(0, MAX_STREET_ADDRESS_LENGTH);
    } else {
        this->streetAddress = streetAddress;
    }
}

string Contact::getStreetAddress() const {
    return streetAddress;
}

void Contact::setCity(string city) {
    this->city = city;
}

string Contact::getCity() const {
    return city;
}

void Contact::setState(string state) {
    this->state = state;
}

string Contact::getState() const{
    return state;
}

void Contact::setZipCode(string zipCode) {
    this->zipCode = zipCode;
}

string Contact::getZipCode() const{
    return zipCode;
}

void Contact::setCountry(string country) {
    this->country = country;
}

string Contact::getCountry() const{
    return country;
}

void Contact::setNotes(string notes) {
    this->notes = notes;
}

string Contact::getNotes() const{
    return notes;
}

int Contact::getID() const{
    return ID;
}


