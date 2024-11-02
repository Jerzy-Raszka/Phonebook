//
// Created by jrasz on 30.10.2024.
//
#include "../include/ContactData.h"

#include <iostream>

std::list<std::shared_ptr<ContactData>> ContactData::contacts;

void addContact(const ContactData& addedContact)
{
    //TODO: if name is the same check lastname
    bool wasAdded = false;
    for (auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it)
    {
        if (addedContact.name.compare((*it)->name) < 0)
        {
            ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
            wasAdded = true;
            break;
        }
    }
    if (!wasAdded)
    {
        ContactData::contacts.push_back(std::make_shared<ContactData>(addedContact));
    }
}


ContactData::ContactData(const std::string& name, const std::string& lastname, const std::string& phoneNumber)
{
    this->name = name;
    this->lastname = lastname;
    this->phoneNumber = phoneNumber;

    addContact(*this);
};
