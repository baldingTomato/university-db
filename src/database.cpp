#include "database.hpp"
#include <iostream>

void Database::addStudent(const std::string& name, const std::string& lastname, const std::string& address, const int& pesel, const Sex& sex) {
    auto result = students_.emplace(counter_, Student(name, lastname, address, pesel, sex));

    if (!result.second) {
        std::cout << "Failed adding student " + name + " " + lastname + " to the database!\n";
    } else {
        incCounter();
    }
}

void Database::selectWholeDatabase() {
    std::cout << "-------------------------------------------------------------------------------------------\n";

    for (auto record : students_) {
        std::cout << std::to_string(record.first) + " " +
                         record.second.getName() + " " +
                         record.second.getLastName() + " " +
                         record.second.getAddress() + " " +
                         std::to_string(record.second.getPesel()) + " " +
                         record.second.getSex() + "\n";
    }

    std::cout << "-------------------------------------------------------------------------------------------\n";
}
