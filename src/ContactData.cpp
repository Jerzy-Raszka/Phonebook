//
// Created by jrasz on 30.10.2024.
//
#include "../include/ContactData.h"

#include <algorithm>
#include <fstream>
#include <iostream>

std::list<std::shared_ptr<ContactData> > ContactData::contacts;

std::string toLowerCase(const std::string &str) {
    std::string lowerStr = str;
    std::ranges::transform(lowerStr, lowerStr.begin(), ::tolower);
    return lowerStr;
}

void addContactAndSort(const ContactData &addedContact) {
    bool isAdded = false;
    const auto newNameToLower = toLowerCase(addedContact.name);
    const auto newLastNameToLower = toLowerCase(addedContact.lastname);

    for (auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it) {
        auto currentNameToLower = toLowerCase((*it)->name);
        auto currentLastNameToLower = toLowerCase((*it)->lastname);

        if (newNameToLower.compare(currentNameToLower) < 0) {
            ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
            isAdded = true;
            break;
        }
        if (newNameToLower == currentNameToLower && newLastNameToLower.compare(currentLastNameToLower) < 0) {
            ContactData::contacts.insert(it, std::make_shared<ContactData>(addedContact));
            isAdded = true;
            break;
        }
    }
    if (!isAdded) {
        ContactData::contacts.push_back(std::make_shared<ContactData>(addedContact));
    }
}

void ContactData::printList(const std::list<std::shared_ptr<ContactData> > &listToPrint) {
    for (const auto &it: listToPrint) {
        std::cout << it->name << " ";
        std::cout << it->lastname << " ";
        std::cout << it->phoneNumber << std::endl;
    }
    std::cout << std::endl;
}

bool ContactData::operator==(const ContactData &other) const {
    return this->name == other.name && this->lastname == other.lastname && this->phoneNumber == other.phoneNumber;
}

void ContactData::searchContacts(const std::string &searchParam) {
    auto searchResult = ContactData::contacts;

    for (auto it = searchResult.begin(); it != searchResult.end(); ++it) {
        if (auto fullData = toLowerCase((*it)->name + (*it)->lastname + (*it)->phoneNumber);
            fullData.find(searchParam) == std::string::npos) {
            it = searchResult.erase(it);
            --it;
        }
    }
    printList(searchResult);
}

void ContactData::removeContact(const ContactData &contactToRemove) {
    for (auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it) {
        if (**it == contactToRemove) {
            contacts.erase(it);
            break;
        }
    }
}

void ContactData::serialize(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for writing." << std::endl;
        return;
    }

    const size_t nameLength = name.size();
    file.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
    file.write(name.c_str(), static_cast<std::streamsize>(nameLength));

    const size_t lastnameLength = lastname.size();
    file.write(reinterpret_cast<const char *>(&lastnameLength), sizeof(lastnameLength));
    file.write(lastname.c_str(), static_cast<std::streamsize>(lastnameLength));

    const size_t phoneNumberLength = phoneNumber.size();
    file.write(reinterpret_cast<const char *>(&phoneNumberLength), sizeof(phoneNumberLength));
    file.write(phoneNumber.c_str(), static_cast<std::streamsize>(phoneNumberLength));

    file.close();
    std::cout << "Object serialized and added to file successfully." << std::endl;
}

void ContactData::deserialize(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for reading." << std::endl;
        return;
    }

    while (file.peek() != EOF) {
        size_t nameLength;
        file.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
        const auto nameBuffer = new char[nameLength + 1];
        file.read(nameBuffer, static_cast<std::streamsize>(nameLength));
        nameBuffer[nameLength] = '\0';
        std::string name(nameBuffer);
        delete[] nameBuffer;

        size_t lastnameLength;
        file.read(reinterpret_cast<char *>(&lastnameLength), sizeof(lastnameLength));
        const auto lastnameBuffer = new char[lastnameLength + 1];
        file.read(lastnameBuffer, static_cast<std::streamsize>(lastnameLength));
        lastnameBuffer[lastnameLength] = '\0';
        std::string lastname(lastnameBuffer);
        delete[] lastnameBuffer;

        size_t phonenumberLength;
        file.read(reinterpret_cast<char *>(&phonenumberLength), sizeof(phonenumberLength));
        const auto phoneBuffer = new char[phonenumberLength + 1];
        file.read(phoneBuffer, static_cast<std::streamsize>(phonenumberLength));
        phoneBuffer[phonenumberLength] = '\0';
        std::string phonenumber(phoneBuffer);
        delete[] phoneBuffer;

        ContactData(name, lastname, phonenumber);
    }

    file.close();
    std::cout << "Objects deserialized successfully." << std::endl;
}

ContactData::ContactData(const std::string &name, const std::string &lastname, const std::string &phoneNumber) {
    this->name = name;
    this->lastname = lastname;
    this->phoneNumber = phoneNumber;

    addContactAndSort(*this);
};
