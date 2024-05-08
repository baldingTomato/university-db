#pragma once

#include <map>
#include <memory>
#include "employee.hpp"
#include "student.hpp"

class Database {
    std::map<std::string, std::unique_ptr<Person>> people_;

public:
    void addPerson(std::unique_ptr<Person> person);
    void selectWholeDatabase();
    // void selectAndSortByPesel();
    void selectAndSortByLastName();
    void selectAndSortByEarnings();
    void updateEarnings(const std::string& pesel, double newEarnings);
    void removePerson(const int& index);
    void searchByLastName(const std::string& lastName);
    void searchByPesel(const std::string& pesel);
    bool checkPeselCorrectness(const std::string& pesel);
    bool isEmpty();
    void generateData();
};
