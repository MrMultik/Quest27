#include <iostream>
#include <locale>
#include <memory>

#include "Dog.h"
#include "Swimming.h"
#include "Dancing.h"
#include "Counting.h"

int main() {
    setlocale(LC_ALL, "");

    std::cout << "=== Практика 29. Задание 1: Суперпёс ===\n";

    std::string name;
    std::cout << "Введите имя собаки: ";
    std::cin >> name;

    Dog dog(name);

    while (true) {
        std::cout << "\nВыберите талант для добавления:\n";
        std::cout << "1 - Плавать\n";
        std::cout << "2 - Танцевать\n";
        std::cout << "3 - Считать\n";
        std::cout << "0 - Завершить выбор\n> ";

        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            dog.addTalent(std::make_unique<Swimming>());
            std::cout << "Талант добавлен\n";
            break;
        case 2:
            dog.addTalent(std::make_unique<Dancing>());
            std::cout << "Талант добавлен\n";
            break;
        case 3:
            dog.addTalent(std::make_unique<Counting>());
            std::cout << "Талант добавлен\n";
            break;
        default:
            std::cout << "Неверный выбор\n";
        }
    }

    std::cout << "\n";
    dog.show_talents();
    return 0;
}