//
// Created by jrasz on 30.10.2024.
//

#ifndef CONTACTDATA_H
#define CONTACTDATA_H



#include <string>
class ContactData {
public:
    std::string name;
    std::string lastname;
    std::string phoneNumber;
    ContactData* next;

    ContactData(const std::string &name, const std::string &lastname, const std::string &phoneNumber);
};



#endif //CONTACTDATA_H
