#pragma once

#include <map>
#include "student.hpp"

class Database {
    std::map<int, Student> students_;
    int counter_ = 0;

    void incCounter() { ++counter_; };

public:
    void addStudent(const std::string& name, const std::string& lastname, const std::string& address, const int& pesel, const Sex& sex);
    void selectWholeDatabase();
    void removeStudent(const int& index);
};
