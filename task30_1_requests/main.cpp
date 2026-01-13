#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    setlocale(LC_ALL, "");

    std::cout << "Задание 1. HTTP-запросы\n";
    std::cout << "Команды: get, post, put, delete, patch, exit\n";

    while (true) {
        std::cout << "\nВведите команду: ";
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "exit") break;

        cpr::Response r;

        if (cmd == "get")
            r = cpr::Get(cpr::Url{ "https://httpbin.org/get" });
        else if (cmd == "post")
            r = cpr::Post(cpr::Url{ "https://httpbin.org/post" });
        else if (cmd == "put")
            r = cpr::Put(cpr::Url{ "https://httpbin.org/put" });
        else if (cmd == "delete")
            r = cpr::Delete(cpr::Url{ "https://httpbin.org/delete" });
        else if (cmd == "patch")
            r = cpr::Patch(cpr::Url{ "https://httpbin.org/patch" });
        else {
            std::cout << "Неизвестная команда\n";
            continue;
        }

        std::cout << "\nОтвет сервера:\n" << r.text << std::endl;
    }
}