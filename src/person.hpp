#pragma once

#include <string>
#include "sex.hpp"

class Person {
    const std::string name_;
    const std::string lastname_;
    const std::string address_;
    const std::string pesel_;
    const Sex sex_;

public:
    Person(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex);

    virtual ~Person() = default;

    virtual std::string getFullName() const;
    virtual std::string getName() const;
    virtual std::string getLastName() const;
    virtual std::string getAddress() const;
    virtual std::string getPesel() const;
    virtual std::string getSex() const;

    virtual double getEarnings() const = 0;
    virtual void setEarnings(const double& earnings) = 0;
    virtual int getIndex() const = 0;
    virtual void setIndex(const int& index) = 0;
    virtual void printData() const = 0;
};
