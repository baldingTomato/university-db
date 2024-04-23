#pragma once

#include <string>
#include "sex.hpp"

class Student {
    const std::string name_;
    const std::string lastname_;
    const std::string address_;
    const std::string pesel_;
    int index_ = 0;
    const Sex sex_;

public:
    Student(std::string name, std::string lastname, std::string address, std::string pesel, Sex sex);

    std::string getFullName() const;
    std::string getName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    std::string getPesel() const;
    std::string getSex() const;
    int getIndex() const;

    void setIndex(const int& index);

    void printData() const;
};
