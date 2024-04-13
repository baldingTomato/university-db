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

    for (const auto& [_, student] : students_) {
        student.printData();
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

void Database::searchByLastName(const std::string& lastName) {
    for (const auto& [_, student] : students_) {
        if (student.getLastName() == lastName) {
            std::cout << "Znaleziono studenta:\n";
            student.printData();
            return;
        }
    }

    std::cout << "Nie ma takiego nazwiska w bazie!\n";
}

void Database::searchByPesel(const int& pesel) {
    for (const auto& [_, student] : students_) {
        if (student.getPesel() == pesel) {
            std::cout << "Znaleziono studenta:\n";
            student.printData();
            return;
        }
    }

    std::cout << "Nie ma takiego peselu w bazie!\n";
}
