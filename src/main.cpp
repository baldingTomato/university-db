#include <iostream>
#include <limits>
#include <string>
#include "database.hpp"

void drawMenu() {
    std::cout << "--------------------" << std::endl;
    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1.Dodaj studenta" << std::endl;
    std::cout << "2.Dodaj pracownika" << std::endl;
    std::cout << "3.Wyszukaj osobe po nazwisku" << std::endl;
    std::cout << "4.Wyszukaj osobe po peselu" << std::endl;
    std::cout << "5.Wyswietl osoby (wedlug peselu)" << std::endl;
    std::cout << "6.Wyswietl osoby wedlug nazwiska" << std::endl;
    std::cout << "7.Usun osobe" << std::endl;
    std::cout << "8.Generuj przypadkowe dane" << std::endl;
    std::cout << "9.Zamknij baze" << std::endl;
    std::cout << "--------------------" << std::endl;
}

int readCommand() {
    int command = 0;

    if (std::cin >> command) {
        if (command == 1 || command == 2 || command == 3 || command == 4 || command == 5 || command == 6 || command == 7 || command == 8 || command == 9) {
            return command;
        } else {
            std::cout << "Nie ma takiej opcji!\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }

    } else {
        std::cout << "Nie ma takiej opcji!\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
}

void readStudentsInfo(Database& db) {
    std::string name;
    std::string lastname;
    std::string address;
    char chosenSex;
    std::string pesel;
    Sex sex;

    std::cout << "Imie: ";
    std::cin >> name;
    std::cout << "Nazwisko: ";
    std::cin >> lastname;
    std::cout << "Adres: ";
    std::cin >> address;
    std::cout << "Pesel: ";
    std::cin >> pesel;
    std::cout << "Plec: (m lub k) ";
    std::cin >> chosenSex;

    if (chosenSex == 'm') {
        sex = Sex::Male;
    } else if (chosenSex == 'k') {
        sex = Sex::Female;
    } else {
        std::cout << "Nie ma takiej opcji!\n";
        return;
    }

    std::unique_ptr<Person> ptr = std::make_unique<Student>(name, lastname, address, pesel, sex);

    db.addPerson(std::move(ptr));
}

void readEmployeeInfo(Database& db) {
    std::string name;
    std::string lastname;
    std::string address;
    char chosenSex;
    std::string pesel;
    Sex sex;

    std::cout << "Imie: ";
    std::cin >> name;
    std::cout << "Nazwisko: ";
    std::cin >> lastname;
    std::cout << "Adres: ";
    std::cin >> address;
    std::cout << "Pesel: ";
    std::cin >> pesel;
    std::cout << "Plec: (m lub k) ";
    std::cin >> chosenSex;

    if (chosenSex == 'm') {
        sex = Sex::Male;
    } else if (chosenSex == 'k') {
        sex = Sex::Female;
    } else {
        std::cout << "Nie ma takiej opcji!\n";
        return;
    }

    std::unique_ptr<Person> ptr = std::make_unique<Employee>(name, lastname, address, pesel, sex);

    db.addPerson(std::move(ptr));
}

void readIndexToRemove(Database& db) {
    int index = -1;
    std::cout << "Podaj indeks osoby, ktora chcesz usunac: ";
    std::cin >> index;

    if (!std::cin) {
        std::cout << "Nie moze istniec taki indeks!\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } else {
        db.removePerson(index);
    }
}

void readLastNameToSearch(Database& db) {
    std::string input;
    std::cout << "Podaj nazwisko do wyszukania: ";
    std::cin >> input;

    db.searchByLastName(input);
}

void readPeselToSearch(Database& db) {
    std::string input;
    std::cout << "Podaj pesel do wyszukania: ";
    std::cin >> input;

    if (!db.checkPeselCorrectness(input)) {
        std::cout << "Nie moze istniec taki pesel!\n\n";
    } else {
        db.searchByPesel(input);
    }
}

int main() {
    Database db;

    while (true) {
        drawMenu();
        switch (readCommand()) {
        case 1:
            std::cout << "Wprowadz dane nowego studenta:\n";
            readStudentsInfo(db);
            break;
        case 2:
            std::cout << "Wprowadz dane nowego pracownika:\n";
            readStudentsInfo(db);
            break;
        case 3:
            readLastNameToSearch(db);
            break;
        case 4:
            readPeselToSearch(db);
            break;
        case 5:
            db.selectWholeDatabase();
            break;
        case 6:
            db.selectAndSortByLastName();
            break;
        case 7:
            readIndexToRemove(db);
            break;
        case 8:
            db.generateData();
            break;
        case 9:
            std::cout << "Koniec!\n";
            return 0;
        default:
            drawMenu();
            break;
        }
    }

    return 0;
}
