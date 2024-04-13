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

    std::string getFullName() const;
    std::string getName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    int getPesel() const;
    std::string getSex() const;
    int getIndex() const;

    void setIndex(const int& index);

    void printData() const;
};
