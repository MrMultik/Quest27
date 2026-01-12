#pragma once
#include <string>

struct BoundingBoxDimensions {
    double width;
    double height;
};

class Shape {
public:
    virtual ~Shape() = default;
    virtual double square() const = 0;
    virtual BoundingBoxDimensions dimensions() const = 0;
    virtual std::string type() const = 0;
};

inline void printParams(Shape* shape) {
    auto dim = shape->dimensions();
    std::cout << "Тип фигуры: " << shape->type() << '\n';
    std::cout << "Площадь: " << shape->square() << '\n';
    std::cout << "Ширина: " << dim.width << '\n';
    std::cout << "Высота: " << dim.height << "\n\n";
}