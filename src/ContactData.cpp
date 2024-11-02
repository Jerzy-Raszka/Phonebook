//
// Created by jrasz on 30.10.2024.
//
#include "../include/ContactData.h"

#include <iostream>

std::list<std::shared_ptr<ContactData>> ContactData::contacts;

void addContact(const ContactData& addedContact)
{
    if (const auto it = std::ranges::find_if(ContactData::contacts, [&](const std::shared_ptr<ContactData>& contact)
    {
        return addedContact.name.compare(contact->name);
    }); it != ContactData::contacts.end())
    {
        std::cout << *it << std::endl;
        ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
    }
    else { ContactData::contacts.push_back(std::make_shared<ContactData>(addedContact)); }
}

ContactData::ContactData(const std::string& name, const std::string& lastname, const std::string& phoneNumber)
{
    this->name = name;
    this->lastname = lastname;
    this->phoneNumber = phoneNumber;

    addContact(*this);
};
