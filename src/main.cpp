#include <iostream>
#include <string>

void drawMenu() {
    std::cout << "--------------------" << std::endl;
    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1.Dodaj studenta" << std::endl;
    std::cout << "2.Wyszukaj studenta" << std::endl;
    std::cout << "3.Wyswietl studentow" << std::endl;
    std::cout << "4.Zamknij baze" << std::endl;
    std::cout << "--------------------" << std::endl;
}

int readCommand() {
    int command = 0;

    if (std::cin >> command) {
        if (command == 1 || command == 2 || command == 3 || command == 4) {
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

int main() {
    drawMenu();

    while (true) {
        switch (readCommand()) {
        case 1:
            std::cout << "Jeden!\n";
            break;
        case 2:
            std::cout << "Dwa!\n";
            break;
        case 3:
            std::cout << "Trzy!\n";
            break;
        case 4:
            std::cout << "Koniec!\n";
            return 0;
        default:
            drawMenu();
            break;
        }
    }

    return 0;
}
