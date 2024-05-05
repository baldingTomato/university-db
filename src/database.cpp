#include "database.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

void Database::addPerson(std::unique_ptr<Person> person) {
    if (!checkPeselCorrectness(person->getPesel())) {
        std::cout << "Taki pesel nie moze istniec!\n";
        return;
    } else if (person->getPesel().at(9) % 2 == 0 && person->getSex() != "Female") {
        std::cout << "Pesel nie pasuje do reszty danych! Dodawanie do bazy przerwane.\n";
        return;
    }

    auto searchedPerson = people_.find(person->getPesel());

    if (searchedPerson != people_.end()) {
        std::cout << "Taka osoba juz znajduje sie w bazie!\n";
        return;
    }

    std::string fullname = person->getFullName();
    person->setIndex(std::stoi(person->getPesel().substr(0, 9)) / 1804);
    auto result = people_.emplace(person->getPesel(), std::move(person));

    if (!result.second) {
        std::cout << "Nie udalo sie dodac osoby " + fullname + " do bazy!\n";
    } else {
        std::cout << "Dodano " + fullname + " do bazy.\n";
    }
}

void Database::selectWholeDatabase() {
    std::cout << "-------------------------------------------------------------------------------------------\n";

    for (const auto& [_, person] : people_) {
        person->printData();
    }

    std::cout << "-------------------------------------------------------------------------------------------\n";
}

// There is no point in sorting by Pesel since values of a map are already sorted by key (by pesel).
//  void Database::selectAndSortByPesel() {
//      std::vector<std::pair<int, std::string>> sortedPesels;
//      sortedPesels.reserve(people_.size());

//     for (const auto& [index, student] : students_) {
//         sortedPesels.emplace_back(index, student.getPesel());
//     }

//     std::sort(sortedPesels.begin(), sortedPesels.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
//         return a.second < b.second;
//     });

//     for (const auto& pesel : sortedPesels) {
//         students_.at(pesel.first).printData();
//     }
// }

void Database::selectAndSortByLastName() {
    std::vector<std::pair<std::string, std::string>> sortedLastNames;
    sortedLastNames.reserve(people_.size());

    for (const auto& [index, student] : people_) {
        sortedLastNames.emplace_back(index, student->getLastName());
    }

    std::sort(sortedLastNames.begin(), sortedLastNames.end(), [](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
        return a.second < b.second;
    });

    for (const auto& [index, _] : sortedLastNames) {
        people_.at(index)->printData();
    }
}

void Database::removePerson(const int& index) {
    auto searchedPerson = std::find_if(people_.cbegin(), people_.cend(), [index](const auto& person) {
        return person.second->getIndex() == index;
    });

    if (searchedPerson != people_.end()) {
        auto stud = people_.extract(searchedPerson);
        std::cout << "Osoba " + stud.mapped()->getFullName() + " zostala usunieta z bazy!\n";
    } else {
        std::cout << "Takiej osoby nie ma w bazie danych!\n";
    }
}

void Database::searchByLastName(const std::string& lastName) {
    for (const auto& [_, person] : people_) {
        if (person->getLastName() == lastName) {
            std::cout << "Znaleziono osobe:\n";
            person->printData();
            return;
        }
    }

    std::cout << "Nie ma takiego nazwiska w bazie!\n";
}

void Database::searchByPesel(const std::string& pesel) {
    auto searchedPerson = people_.find(pesel);

    if (searchedPerson != people_.end()) {
        std::cout << "Znaleziono osobe:\n";
        searchedPerson->second->printData();
        return;
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
    if (people_.empty()) {
        return true;
    }

    return false;
}
