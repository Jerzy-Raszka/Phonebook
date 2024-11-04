#include <iostream>
#include <string>
#include "../include/ContactData.h"

int main()
{
    ContactData con5("adam", "Zakon", "777666999");
    ContactData con2("Bartek", "Raszka", "669114472");
    ContactData con1("Adam", "raszka", "669114472");
    ContactData con4("Damian", "Raszka", "669114472");
    ContactData con3("Czarek", "Raszka", "669114472");
    ContactData con7("Adam", "aaszka", "669114472");
    //TODO: zrób funkcje print listy i wywołuj ją z listą jako parametrem
    for (const auto& contact : ContactData::contacts)
    {
        std::cout << contact->name << " ";
        std::cout << contact->lastname << " ";
        std::cout << contact->phoneNumber << std::endl;
    }

    ContactData::searchContacts("777");

    for (const auto& contact : ContactData::contacts)
    {
        std::cout << contact->name << " ";
        std::cout << contact->lastname << " ";
        std::cout << contact->phoneNumber << std::endl;
    }

    return 0;
}
