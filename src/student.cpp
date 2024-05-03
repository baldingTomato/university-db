#include "student.hpp"
#include <iostream>

Student::Student(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex)
    : Person(name, lastname, address, pesel, sex){};

int Student::getIndex() const {
    return index_;
};

void Student::setIndex(const int& index) {
    index_ = index;
}

void Student::printData() const {
    std::cout << std::to_string(index_) + " " +
                     getName() + " " +
                     getLastName() + " " +
                     getAddress() + " " +
                     getPesel() + " " +
                     getSex() + "\n";
}
