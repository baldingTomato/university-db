#include "database.hpp"
#include <iostream>

void Database::addStudent(const std::string& name, const std::string& lastname, const std::string& address, const int& pesel, const Sex& sex) {
    auto result = students_.emplace(counter_, Student(name, lastname, address, pesel, sex));

    if (!result.second) {
        std::cout << "Failed adding student " + name + " " + lastname + " to the database!\n";
    } else {
        students_.at(counter_).setIndex(counter_);
        incCounter();
    }
}

void Database::selectWholeDatabase() {
    std::cout << "-------------------------------------------------------------------------------------------\n";

    for (auto record : students_) {
        std::cout << std::to_string(record.second.getIndex()) + " " +
                         record.second.getName() + " " +
                         record.second.getLastName() + " " +
                         record.second.getAddress() + " " +
                         std::to_string(record.second.getPesel()) + " " +
                         record.second.getSex() + "\n";
    }

    std::cout << "-------------------------------------------------------------------------------------------\n";
}

void Database::removeStudent(const int& index) {
    auto stud = students_.extract(index);
    if (stud.empty()) {
        std::cout << "Takiego studenta nie ma w bazie danych studentów!\n";
    } else {
        std::cout << "Student " + stud.mapped().getFullName() + " zostal usuniety z bazy!\n";
    }
}
