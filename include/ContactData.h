//
// Created by jrasz on 30.10.2024.
//

#ifndef CONTACTDATA_H
#define CONTACTDATA_H


#include <string>
#include <list>
#include <memory>


class ContactData
{
public:
    static std::list<std::shared_ptr<ContactData>> contacts;
    std::string name;
    std::string lastname;
    std::string phoneNumber;

    static void printList(const std::list<std::shared_ptr<ContactData>>&);

    bool operator==(const ContactData& other) const;

    static void searchContacts(const std::string& searchParam);

    static void removeContact(const ContactData&);

    ContactData(const std::string& name, const std::string& lastname, const std::string& phoneNumber);
};


#endif //CONTACTDATA_H
