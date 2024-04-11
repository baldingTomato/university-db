#pragma once

#include <string>
#include "sex.hpp"

class Student {
    const std::string name_;
    const std::string lastname_;
    const std::string address_;
    int index_;
    const int pesel_;
    const Sex sex_;

public:
    Student(std::string name, std::string lastname, std::string address, int pesel, Sex sex);

    std::string getFullName();
    std::string getName();
    std::string getLastName();
    std::string getAddress();
    int getPesel();
    std::string getSex();
    int getIndex();
};
