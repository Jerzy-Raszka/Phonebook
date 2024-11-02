#include <iostream>
#include <string>
#include "../include/ContactData.h"

int main()
{
    ContactData con1("Adam", "Raszka", "669114472");
    ContactData con2("Bartek", "Raszka", "669114472");
    ContactData con4("Damian", "Raszka", "669114472");
    ContactData con3("Czarek", "Raszka", "669114472");

    for (const auto& contact : ContactData::contacts)
    {
        std::cout << contact->name << std::endl;
    }

    return 0;
}
