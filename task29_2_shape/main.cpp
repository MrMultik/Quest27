#include <iostream>
#include <locale>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    setlocale(LC_ALL, "");

    std::cout << "=== Практика 29. Задание 2: Интерфейс Shape ===\n\n";

    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);

    printParams(&c);
    printParams(&r);
    printParams(&t);

    return 0;
}