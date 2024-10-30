cmake_minimum_required(VERSION 3.29)
project(Phonebook)

set(CMAKE_CXX_STANDARD 20)

add_executable(Phonebook src/main.cpp
        src/ContactData.cpp
        include/ContactData.h)
