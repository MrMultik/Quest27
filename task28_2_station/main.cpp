#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <clocale>

std::mutex stationMutex;

void train(const std::string& name, int travelTime) {
    std::this_thread::sleep_for(std::chrono::seconds(travelTime));

    {
        std::lock_guard<std::mutex> lock(stationMutex);
        std::cout << "Поезд " << name << " прибыл на вокзал\n";
        std::cout << "Введите команду 'depart' для отправления поезда "
            << name << ": ";
        std::string cmd;
        std::cin >> cmd;
        std::cout << "Поезд " << name << " покинул вокзал\n\n";
    }
}

int main() {
    setlocale(LC_ALL, "");

    std::cout << "=== Задание 28.2: Симуляция вокзала ===\n";
    std::cout << "Введите время в пути (в секундах)\n\n";

    int tA, tB, tC;
    std::cout << "Поезд A: "; std::cin >> tA;
    std::cout << "Поезд B: "; std::cin >> tB;
    std::cout << "Поезд C: "; std::cin >> tC;

    std::thread A(train, "A", tA);
    std::thread B(train, "B", tB);
    std::thread C(train, "C", tC);

    A.join();
    B.join();
    C.join();

    std::cout << "Все поезда посетили вокзал.\n";
    return 0;
}