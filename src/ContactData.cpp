//
// Created by jrasz on 30.10.2024.
//
#include "../include/ContactData.h"

#include <algorithm>
#include <iostream>

std::list<std::shared_ptr<ContactData>> ContactData::contacts;

std::string toLowerCase(const std::string& str)
{
    std::string lowerStr = str;
    std::ranges::transform(lowerStr, lowerStr.begin(), ::tolower);
    return lowerStr;
}

void addContact(const ContactData& addedContact)
{
    //TODO: name lowercase function better
    //TODO: name lower cased name better
    //TODO: do lower case for lastname too
    bool wasAdded = false;
    const auto newToLower = toLowerCase(addedContact.name);

    for (auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it)
    {
        auto existingToLower = toLowerCase((*it)->name);

        if (newToLower.compare(existingToLower) < 0)
        {
            ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
            wasAdded = true;
            break;
        }
        if (newToLower == existingToLower && addedContact.lastname.compare((*it)->lastname) < 0)
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
