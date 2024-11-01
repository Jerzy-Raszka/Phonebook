#include <iostream>
#include <string>
#include <list>
#include <algorithm>
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

    if (const auto it = std::ranges::find_if(contacts,
                                             [&](ContactData const& p)
                                             {
                                                 return p.name == "Kamil";
                                             }); it != contacts.end())
    {
        contacts.insert(it, z);
    }
    else{contacts.push_front(z);}

    for (const auto& n : contacts)
    {
        std::cout << n.name << std::endl;
    }

    return 0;
}
