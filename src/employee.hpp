#pragma once

#include <string>
#include "person.hpp"

class Employee : public Person {
    double earnings_ = 3400.0;

public:
    Employee(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex);

    int getIndex() const override { return 0; };
    void setIndex(const int&) override{};

    double getEarnings() const override;
    void setEarnings(const double&) override;

    void printData() const override;
};
