#pragma once

#include <string>
#include "person.hpp"

class Student : public Person {
    int index_ = 0;

public:
    Student(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex);

    int getIndex() const override;
    void setIndex(const int&) override;

    double getEarnings() const override { return 0; };
    void setEarnings(const double&) override{};

    void printData() const override;
};
