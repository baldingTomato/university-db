#include "student.hpp"

Student::Student(std::string name, std::string lastname, std::string address, int pesel, Sex sex)
    : name_(name), lastname_(lastname), address_(address), pesel_(pesel), sex_(sex){};

std::string Student::getFullName() {
    return name_ + " " + lastname_;
}

std::string Student::getName() {
    return name_;
};

std::string Student::getLastName() {
    return lastname_;
};

std::string Student::getAddress() {
    return address_;
};

int Student::getPesel() {
    return pesel_;
};

std::string Student::getSex() {
    if (sex_ == Sex::Male) {
        return "Male";
    } else {
        return "Female";
    }
}

int Student::getIndex() {
    return index_;
};

void Student::setIndex(const int& index) {
    index_ = index;
}
