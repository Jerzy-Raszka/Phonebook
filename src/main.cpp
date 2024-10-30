#include <iostream>
#include <string>

#include "../include/ContactData.h"

int main() {
    const auto x = ContactData("Jerzy", "Raszka", "669114472");
    std::cout << x.name;
    std::cout << x.lastname;
    std::cout << x.phoneNumber;
    return 0;
}