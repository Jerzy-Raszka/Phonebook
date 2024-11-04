#include <iostream>
#include <string>
#include "../include/ContactData.h"

int main()
{
    ContactData con5("adam", "Zakon", "669114472");
    ContactData con2("Bartek", "Raszka", "669114472");
    ContactData con1("Adam", "raszka", "669114472");
    ContactData con4("Damian", "Raszka", "669114472");
    ContactData con3("Czarek", "Raszka", "669114472");
    ContactData con7("Adam", "aaszka", "669114472");

    for (const auto& contact : ContactData::contacts)
    {
        std::cout << contact->name << " ";
        std::cout << contact->lastname << " ";
        std::cout << contact->phoneNumber << std::endl;
    }

    ContactData::searchContacts("dam");

    for (const auto& contact : ContactData::contacts)
    {
        std::cout << contact->name << " ";
        std::cout << contact->lastname << " ";
        std::cout << contact->phoneNumber << std::endl;
    }

    return 0;
}
