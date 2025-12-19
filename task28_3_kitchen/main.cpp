#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <cstdlib>
#include <string>
#include <vector>
#include <clocale>
#include <iomanip>
#include <atomic>

std::mutex kitchenMutex;
std::mutex coutMutex;
std::queue<std::string> readyMeals;
std::atomic<int> ordersGenerated{ 0 };
std::atomic<int> ordersDelivered{ 0 };
const int TOTAL_ORDERS = 10;

std::vector<std::string> dishes = {
    "Пицца", "Суп", "Стейк", "Салат", "Суши",
    "Бургер", "Паста", "Курица", "Креветки", "Панкейки"
};

void printHeader() {
    std::cout << "================================================\n";
    std::cout << "   СИМУЛЯЦИЯ РАБОТЫ КУХНИ ОНЛАЙН-РЕСТОРАНА\n";
    std::cout << "================================================\n";
}

void printStatus() {
    std::lock_guard<std::mutex> lock(coutMutex);

    std::cout << "\n=== СТАТУС СИСТЕМЫ ===\n";
    std::cout << "Заказов принято: " << ordersGenerated << " / " << TOTAL_ORDERS << "\n";
    std::cout << "Заказов доставлено: " << ordersDelivered << " / " << TOTAL_ORDERS << "\n";

    std::lock_guard<std::mutex> kitchenLock(kitchenMutex);
    std::cout << "Готовых блюд на кухне: " << readyMeals.size() << "\n";
    std::cout << "==============================\n\n";
}

std::string randomDish() {
    return dishes[std::rand() % dishes.size()];
}

void cook(const std::string dish, int orderNumber) {
    // Время приготовления от 5 до 15 секунд
    int cookTime = 5 + std::rand() % 11;

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[ПОВАР] Начал готовить заказ #" << orderNumber
            << ": " << dish << " (время: " << cookTime << " сек)\n";
    }

    std::this_thread::sleep_for(std::chrono::seconds(cookTime));

    {
        std::lock_guard<std::mutex> lock(kitchenMutex);
        readyMeals.push(dish);

        std::lock_guard<std::mutex> coutLock(coutMutex);
        std::cout << "[ПОВАР] Заказ #" << orderNumber << " готов: "
            << dish << "\n";
    }
}

void orderGenerator() {
    int orderNum = 1;

    while (ordersGenerated < TOTAL_ORDERS) {
        // Время между заказами от 5 до 10 секунд
        int waitTime = 5 + std::rand() % 6;
        std::this_thread::sleep_for(std::chrono::seconds(waitTime));

        std::string dish = randomDish();
        ordersGenerated++;

        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[СИСТЕМА] Поступил новый заказ #" << orderNum
                << ": " << dish << "\n";
        }

        // Запускаем повара для приготовления блюда
        std::thread([dish, orderNum]() {
            cook(dish, orderNum);
            }).detach();

        orderNum++;
        printStatus();
    }

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[СИСТЕМА] Генератор заказов завершил работу\n";
    }
}

void courier() {
    while (ordersDelivered < TOTAL_ORDERS) {
        std::this_thread::sleep_for(std::chrono::seconds(30));

        std::lock_guard<std::mutex> lock(kitchenMutex);
        while (!readyMeals.empty() && ordersDelivered < TOTAL_ORDERS) {
            std::string dish = readyMeals.front();
            readyMeals.pop();
            ordersDelivered++;

            std::lock_guard<std::mutex> coutLock(coutMutex);
            std::cout << "[КУРЬЕР] Доставил заказ #" << ordersDelivered
                << ": " << dish << "\n";

            printStatus();

            if (ordersDelivered < TOTAL_ORDERS) {
                // Время на доставку от 10 до 20 секунд
                int deliveryTime = 10 + std::rand() % 11;
                std::this_thread::sleep_for(std::chrono::seconds(deliveryTime));

                std::lock_guard<std::mutex> coutLock2(coutMutex);
                std::cout << "[КУРЬЕР] Вернулся на кухну\n";
            }
        }

        if (ordersDelivered < TOTAL_ORDERS) {
            std::lock_guard<std::mutex> coutLock(coutMutex);
            std::cout << "[КУРЬЕР] Жду готовые заказы...\n";
        }
    }

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[СИСТЕМА] Курьер завершил работу\n";
    }
}

int main() {
    setlocale(LC_ALL, "");
    std::srand(static_cast<unsigned>(time(nullptr)));

    printHeader();

    std::cout << "\nСимуляция запущена! Всего будет обработано "
        << TOTAL_ORDERS << " заказов.\n";
    std::cout << "Система работает автоматически.\n\n";

    // Запускаем потоки
    std::thread generator(orderGenerator);
    std::thread delivery(courier);

    // Ждем завершения потоков
    generator.join();
    delivery.join();

    std::cout << "\n=== ИТОГОВЫЙ ОТЧЕТ ===\n";
    std::cout << "Всего заказов сгенерировано: " << ordersGenerated << "\n";
    std::cout << "Всего заказов доставлено: " << ordersDelivered << "\n";

    std::lock_guard<std::mutex> kitchenLock(kitchenMutex);
    std::cout << "Осталось на кухне: " << readyMeals.size() << " блюд\n";

    std::cout << "\nСимуляция завершена успешно!\n";

    return 0;
}