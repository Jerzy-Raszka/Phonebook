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

    ContactData::printList(ContactData::contacts);

    ContactData::searchContacts("777");
    ContactData::removeContact(con3);

    ContactData::printList(ContactData::contacts);

    return 0;
}
