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
    bool isAdded = false;
    const auto newNameToLower = toLowerCase(addedContact.name);
    const auto newLastNameToLower = toLowerCase(addedContact.lastname);

    for (auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it)
    {
        auto currentNameToLower = toLowerCase((*it)->name);
        auto currentLastNameToLower = toLowerCase((*it)->lastname);

        if (newNameToLower.compare(currentNameToLower) < 0)
        {
            ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
            isAdded = true;
            break;
        }
        if (newNameToLower == currentNameToLower && newLastNameToLower.compare(currentLastNameToLower) < 0)
        {
            ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
            isAdded = true;
            break;
        }
    }
    if (!isAdded)
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
