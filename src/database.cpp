#include "database.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

void Database::addStudent(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex) {
    if (pesel.at(9) % 2 == 0 && sex != Sex::Female) {
        std::cout << "Pesel nie pasuje do reszty danych studenta! Dodawanie do bazy przerwane.\n";
        return;
    }

    auto result = students_.emplace(counter_, Student(name, lastname, address, pesel, sex));

    if (!result.second) {
        std::cout << "Nie udalo sie dodac studenta " + name + " " + lastname + " do bazy!\n";
    } else {
        students_.at(counter_).setIndex(counter_);
        std::cout << "Dodano studenta do bazy.\n";
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

void Database::selectAndSortByPesel() {
    std::vector<std::pair<int, std::string>> sortedPesels;
    sortedPesels.reserve(students_.size());

    for (const auto& [index, student] : students_) {
        sortedPesels.emplace_back(index, student.getPesel());
    }

    std::sort(sortedPesels.begin(), sortedPesels.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return a.second < b.second;
    });

    for (const auto& pesel : sortedPesels) {
        students_.at(pesel.first).printData();
    }
}

void Database::selectAndSortByLastName() {
    std::vector<std::pair<int, std::string>> sortedLastNames;
    sortedLastNames.reserve(students_.size());

    for (const auto& [index, student] : students_) {
        sortedLastNames.emplace_back(index, student.getLastName());
    }

    std::sort(sortedLastNames.begin(), sortedLastNames.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return a.second < b.second;
    });

    for (const auto& lastName : sortedLastNames) {
        students_.at(lastName.first).printData();
    }
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

void Database::searchByPesel(const std::string& pesel) {
    for (const auto& [_, student] : students_) {
        if (student.getPesel() == pesel) {
            std::cout << "Znaleziono studenta:\n";
            student.printData();
            return;
        }
    }

    std::cout << "Nie ma takiego peselu w bazie!\n";
}

bool Database::checkPeselCorrectness(const std::string& pesel) {
    if (pesel.length() != 11) {
        return false;
    }

    std::vector<int> convertedPesel;
    convertedPesel.reserve(10);
    std::transform(pesel.begin(), pesel.end() - 1, std::back_inserter(convertedPesel),
                   [](char c) { return c - '0'; });

    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    int sum_of_products = std::inner_product(convertedPesel.begin(), convertedPesel.end(), weights.begin(), 0);

    int controlDigit = 10 - (sum_of_products % 10);

    if ((pesel.at(10) - '0') != controlDigit) {
        return false;
    }

    return true;
}

bool Database::isEmpty() {
    if (students_.empty()) {
        return true;
    }

    return false;
}
