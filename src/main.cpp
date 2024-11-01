#include <iostream>
#include <string>
#include <list>
#include "../include/ContactData.h"

int main()
{
    std::list<ContactData> contacts;

    const auto x = ContactData("Jerzy", "Raszka", "669114472");
    contacts.push_front(x);
    const auto y = ContactData("Adam", "Raszka", "669114472");
    contacts.push_front(y);
    const auto z = ContactData("Romek", "Raszka", "669114472");

    contacts.emplace_back("Bartek", "Raszka", "669114472");


    for (const auto& n : contacts)
    {
        std::cout << n.name << std::endl;
    }

    //How to find pos of element with matching object name
    if (auto it = std::find(contacts.begin(), contacts.end(), name == "Jerzy"); it != contacts.end())
    {
        contacts.insert(it, z);
    }

    return 0;
}
