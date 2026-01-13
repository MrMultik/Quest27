#include <iostream>
#include <map>
#include <vector>
#include <cpr/cpr.h>

int main() {
    setlocale(LC_ALL, "");

    std::cout << "Задание 3. Запросы с аргументами\n";
    std::cout << "Вводите пары ключ-значение\n";
    std::cout << "Введите get или post как КЛЮЧ для отправки\n\n";

    std::map<std::string, std::string> args;

    while (true) {
        std::string key;
        std::cout << "Ключ: ";
        std::cin >> key;

        if (key == "get" || key == "post") {
            if (key == "get") {
                std::string url = "https://httpbin.org/get?";
                bool first = true;
                for (auto& p : args) {
                    if (!first) url += "&";
                    url += p.first + "=" + p.second;
                    first = false;
                }
                auto r = cpr::Get(cpr::Url{ url });
                std::cout << "\nОтвет сервера:\n" << r.text << std::endl;
            }
            else {
                std::vector<cpr::Pair> payload;
                for (auto& p : args)
                    payload.emplace_back(p.first, p.second);

                auto r = cpr::Post(
                    cpr::Url{ "https://httpbin.org/post" },
                    cpr::Payload(payload.begin(), payload.end())
                );
                std::cout << "\nОтвет сервера:\n" << r.text << std::endl;
            }
            break;
        }

        std::string value;
        std::cout << "Значение: ";
        std::cin >> value;
        args[key] = value;
    }
}