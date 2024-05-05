#include "employee.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

Employee::Employee(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex)
    : Person(name, lastname, address, pesel, sex){};

double Employee::getEarnings() const {
    return earnings_;
};

void Employee::setEarnings(const double& earnings) {
    earnings_ = earnings;
}

void Employee::printData() const {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << earnings_;
    
    std::cout << ss.str() << " " +
                     getName() + " " +
                     getLastName() + " " +
                     getAddress() + " " +
                     getPesel() + " " +
                     getSex() + "\n";
}
