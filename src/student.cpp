#include "student.hpp"
#include <iostream>

Student::Student(std::string name, std::string lastname, std::string address, int pesel, Sex sex)
    : name_(name), lastname_(lastname), address_(address), pesel_(pesel), sex_(sex){};

std::string Student::getFullName() const {
    return name_ + " " + lastname_;
}

std::string Student::getName() const {
    return name_;
};

std::string Student::getLastName() const {
    return lastname_;
};

std::string Student::getAddress() const {
    return address_;
};

int Student::getPesel() const {
    return pesel_;
};

std::string Student::getSex() const {
    if (sex_ == Sex::Male) {
        return "Male";
    } else {
        return "Female";
    }
}

int Student::getIndex() const {
    return index_;
};

void Student::setIndex(const int& index) {
    index_ = index;
}

void Student::printData() const {
    std::cout << std::to_string(index_) + " " +
                     name_ + " " +
                     lastname_ + " " +
                     address_ + " " +
                     std::to_string(pesel_) + " " +
                     getSex() + "\n";
}
