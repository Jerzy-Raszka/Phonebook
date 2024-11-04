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

    static void searchContacts(const std::string& searchParam);

    ContactData(const std::string& name, const std::string& lastname, const std::string& phoneNumber);

};


#endif //CONTACTDATA_H
