//
// Created by jrasz on 30.10.2024.
//

#include "../include/ContactData.h"
ContactData::ContactData(const std::string &name, const std::string &lastname, const std::string &phoneNumber) {
    this->name = name;
    this->lastname = lastname;
    this->phoneNumber = phoneNumber;
    this->next = nullptr;
};