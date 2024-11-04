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



void addContactAndSort(const ContactData& addedContact)
{
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

void ContactData::printList(const std::list<std::shared_ptr<ContactData>>& listToPrint) {
    for (const auto & it : listToPrint) {
        std::cout << it->name << " ";
        std::cout << it->lastname << " ";
        std::cout << it->phoneNumber << std::endl;
    }
    std::cout << std::endl;
}

bool ContactData::operator==(const ContactData &other) const {
    return this->name == other.name && this->lastname == other.lastname && this->phoneNumber == other.phoneNumber;
}

void ContactData::searchContacts(const std::string& searchParam)
{
    auto searchResult = ContactData::contacts;

    for(auto it = searchResult.begin(); it != searchResult.end(); ++it) {
        if(auto fullData = toLowerCase((*it)->name + (*it)->lastname + (*it)->phoneNumber); fullData.find(searchParam) == std::string::npos) {
            it = searchResult.erase(it);
            --it;
        }
    }
    printList(searchResult);
}

void ContactData::removeContact(const ContactData& contactToRemove) {
    for(auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it) {
        if (**it == contactToRemove) {
            contacts.erase(it);
            break;
        }
    }
}

ContactData::ContactData(const std::string& name, const std::string& lastname, const std::string& phoneNumber)
{
    this->name = name;
    this->lastname = lastname;
    this->phoneNumber = phoneNumber;

    addContactAndSort(*this);

};
