#include <string>
#include "Contact.h"



using std::string;

Contact::Contact(
    string name, string phoneNumber, string email, string streetAddress,
    string city, string state, string zipCode, string country, string notes
    ) {
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
    this->name = (name.length() > MAX_NAME_LENGTH) ? name.substr(0, MAX_NAME_LENGTH) : name;
}

string Contact::getName() const {
    return name;
}

void Contact::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = (phoneNumber.length() > MAX_PHONE_NUMBER_LENGTH) ? phoneNumber.substr(0, MAX_PHONE_NUMBER_LENGTH) : phoneNumber;
}

string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::setEmail(string email) {
    this->email = (email.length() > MAX_EMAIL_LENGTH) ? email.substr(0, MAX_EMAIL_LENGTH) : email;
}

string Contact::getEmail() const {
    return email;
}

void Contact::setStreetAddress(string streetAddress) {
    this->streetAddress = (streetAddress.length() > MAX_STREET_ADDRESS_LENGTH) ? streetAddress.substr(0, MAX_STREET_ADDRESS_LENGTH) : streetAddress;
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

string Contact::getState() const {
    return state;
}

void Contact::setZipCode(string zipCode) {
    this->zipCode = zipCode;
}

string Contact::getZipCode() const {
    return zipCode;
}

void Contact::setCountry(string country) {
    this->country = country;
}

string Contact::getCountry() const {
    return country;
}

void Contact::setNotes(string notes) {
    this->notes = notes;
}

string Contact::getNotes() const {
    return notes;
}

int Contact::getID() const {
    return ID;
}
