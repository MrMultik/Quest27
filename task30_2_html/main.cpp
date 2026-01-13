#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    setlocale(LC_ALL, "");

    std::cout << "Задание 2. Захват HTML-заголовка\n";

    auto r = cpr::Get(
        cpr::Url{ "https://httpbin.org/html" },
        cpr::Header{ {"accept", "text/html"} }
    );

    std::string html = r.text;

    size_t start = html.find("<h1>");
    size_t end = html.find("</h1>");

    if (start != std::string::npos && end != std::string::npos) {
        start += 4;
        std::string title = html.substr(start, end - start);
        std::cout << "Заголовок статьи:\n" << title << std::endl;
    }
    else {
        std::cout << "Заголовок не найден\n";
    }
}