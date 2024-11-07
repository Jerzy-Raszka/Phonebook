#include <iostream>
#include <string>
#include <map>
#include "../include/ContactData.h"

void createContact() {
    std::string name, lastname, phonenumber;

    std::cout << "Please input name:" << std::endl;
    std::getline(std::cin >> std::ws, name);
    std::cout << "Please input lastname:" << std::endl;
    std::getline(std::cin, lastname);
    std::cout << "Please input phonenumber:" << std::endl;
    std::getline(std::cin, phonenumber);

    ContactData(name, lastname, phonenumber);
}

void searchInput() {
    std::string searchParam;
    std::cout << "Please input what to search for:" << std::endl;
    std::getline(std::cin >> std::ws, searchParam);
    ContactData::searchContacts(searchParam);
}


void createMap() {
    std::map<int, ContactData> mapContacts;
    int i = 1;
    int contactToRemove;

    for (auto it = ContactData::contacts.begin(); it != ContactData::contacts.end(); ++it, ++i) {
        mapContacts.insert({i, **it});
    }
    for (const auto &contact: mapContacts) {
        std::cout << contact.first << ": " << contact.second.name << " " << contact.second.lastname << " " << contact.
                second.phoneNumber << std::endl;
    }
    do {
        std::cout << "Choose correct number of contact you wish to remove or press 0 if you wish to abandon" <<
                std::endl;
        std::cin >> contactToRemove;
    } while (contactToRemove < 0 || contactToRemove > i);

    if (contactToRemove != 0) {
        const auto deletedCon = mapContacts.find(contactToRemove)->second;
        ContactData::removeContact(deletedCon);
    }
}

int main() {
    bool running = true;
    uint8_t option;
    ContactData::deserialize("data.bin");

    while (running) {
        std::cout << "Please select on of the options listed bellow: " << std::endl << std::endl;;
        std::cout << "1. List all contacts" << std::endl;
        std::cout << "2. Add a new contact" << std::endl;
        std::cout << "3. Delete a contact" << std::endl;
        std::cout << "4. Search for a contact" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> option;

        switch (option) {
            case '1':
                ContactData::printList(ContactData::contacts);
                break;
            case '2':
                createContact();
                break;
            case '3':
                createMap();
                break;
            case '4':
                searchInput();
                break;
            case '5':
                ContactData::serialize("data.bin");
                running = false;
                break;
            default:
                std::cout << "Please input correct value" << std::endl;
                break;
        }
    }
}
