#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <iomanip>
#include <clocale>
#include <algorithm>

struct Swimmer {
    std::string name;
    double speed;   // м/с
    double distance = 0.0;
    int time = 0;
};

std::mutex coutMutex;

void swim(Swimmer& s) {
    while (s.distance < 100.0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        s.distance += s.speed;
        s.time++;

        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Пловец " << s.name
            << " проплыл " << (s.distance > 100.0 ? 100.0 : s.distance)
            << " м\n";
    }
}

int main() {
    setlocale(LC_ALL, "");

    std::cout << "=== Задание 28.1: Заплыв на 100 метров ===\n";
    std::cout << "Введите имя и скорость (м/с) для 6 пловцов\n\n";

    std::vector<Swimmer> swimmers(6);

    for (int i = 0; i < 6; ++i) {
        std::cout << "Пловец " << i + 1 << " имя: ";
        std::cin >> swimmers[i].name;
        std::cout << "Скорость (м/с): ";
        std::cin >> swimmers[i].speed;
    }

    std::vector<std::thread> threads;
    for (auto& s : swimmers) {
        threads.emplace_back(swim, std::ref(s));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::sort(swimmers.begin(), swimmers.end(),
        [](const Swimmer& a, const Swimmer& b) {
            return a.time < b.time;
        });

    std::cout << "\n=== Итоговые результаты ===\n";
    std::cout << "================================\n";

    // Вывод победителя отдельно
    std::cout << "\nПОБЕДИТЕЛЬ: " << swimmers[0].name
        << " — " << swimmers[0].time << " сек\n";
    std::cout << "--------------------------------\n";

    // Вывод остальных участников
    for (size_t i = 1; i < swimmers.size(); ++i) {
        std::cout << i + 1 << ". "
            << swimmers[i].name
            << " — " << swimmers[i].time << " сек\n";
    }

    std::cout << "================================\n";

    // Дополнительное поздравление
    std::cout << "\nПоздравляем " << swimmers[0].name
        << " с победой в заплыве на 100 метров!\n";

    return 0;
}