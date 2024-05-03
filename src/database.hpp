#pragma once

#include <map>
#include <memory>
#include "student.hpp"

class Database {
    std::map<std::string, std::unique_ptr<Person>> people_;

public:
    void addStudent(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex);
    void addEmployee(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex, const double& earnings);
    void selectWholeDatabase();
    void selectAndSortByPesel();
    void selectAndSortByLastName();
    void removeStudent(const int& index);
    void searchByLastName(const std::string& lastName);
    void searchByPesel(const std::string& pesel);
    bool checkPeselCorrectness(const std::string& pesel);
    bool isEmpty();
};
