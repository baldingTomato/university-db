#include "person.hpp"

Person::Person(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex)
    : name_(name), lastname_(lastname), address_(address), pesel_(pesel), sex_(sex){};

std::string Person::getFullName() const {
    return name_ + " " + lastname_;
}

std::string Person::getName() const {
    return name_;
};

std::string Person::getLastName() const {
    return lastname_;
};

std::string Person::getAddress() const {
    return address_;
};

std::string Person::getPesel() const {
    return pesel_;
};

std::string Person::getSex() const {
    if (sex_ == Sex::Male) {
        return "Male";
    } else {
        return "Female";
    }
}