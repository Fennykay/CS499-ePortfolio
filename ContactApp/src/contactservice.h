#ifndef CONTACTSERVICE_H
#define CONTACTSERVICE_H

#include "Contact.h"
#include <vector>

using std::vector;

class contactservice
{
public:
    contactservice();
    ~contactservice();
    void addContact();
    void removeContact();
    void updateContact();
    void getContact();
    vector<Contact> getContacts();

};

#endif // CONTACTSERVICE_H
