#pragma once

#include <map>
#include "student.hpp"

class Database {
    std::map<int, Student> students_;
    int counter_ = 0;

    void incCounter() { ++counter_; };

public:
    void addStudent(const std::string& name, const std::string& lastname, const std::string& address, const std::string& pesel, const Sex& sex);
    void selectWholeDatabase();
    void selectAndSortByPesel();
    void selectAndSortByLastName();
    void removeStudent(const int& index);
    void searchByLastName(const std::string& lastName);
    void searchByPesel(const std::string& pesel);
    bool checkPeselCorrectness(const std::string& pesel);
    bool isEmpty();
};
