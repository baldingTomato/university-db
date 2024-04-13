#include <iostream>
#include <limits>
#include <string>
#include "database.hpp"

void drawMenu() {
    std::cout << "--------------------" << std::endl;
    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1.Dodaj studenta" << std::endl;
    std::cout << "2.Wyszukaj studenta po nazwisku" << std::endl;
    std::cout << "3.Wyszukaj studenta po peselu" << std::endl;
    std::cout << "4.Wyswietl studentow" << std::endl;
    std::cout << "5.Usun studenta" << std::endl;
    std::cout << "6.Zamknij baze" << std::endl;
    std::cout << "--------------------" << std::endl;
}

int readCommand() {
    int command = 0;

    if (std::cin >> command) {
        if (command == 1 || command == 2 || command == 3 || command == 4 || command == 5) {
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
    int pesel = 0;
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

    db.addStudent(name, lastname, address, pesel, sex);
}

void readIndexToRemove(Database& db) {
    int index = -1;
    std::cout << "Podaj indeks studenta, ktorego chcesz usunac: ";
    std::cin >> index;

    if (!std::cin) {
        std::cout << "Nie moze istniec taki indeks!\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } else {
        db.removeStudent(index);
    }
}

void readLastNameToSearch(Database& db) {
    std::string input;
    std::cout << "Podaj nazwisko do wyszukania: ";
    std::cin >> input;

    db.searchByLastName(input);
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
            readLastNameToSearch(db);
            break;
        case 3:
            db.selectWholeDatabase();
            break;
        case 4:
            readIndexToRemove(db);
            break;
        case 5:
            std::cout << "Koniec!\n";
            return 0;
        default:
            drawMenu();
            break;
        }
    }

    return 0;
}
