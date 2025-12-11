#pragma once
#include <string>

// Цвета
enum class Color { None = 0, Red = 1, Green = 2, Blue = 3 };

// Простой ось-выравненный прямоугольник
struct Rect {
    double xmin, ymin, xmax, ymax;
    Rect(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)
        : xmin(x1), ymin(y1), xmax(x2), ymax(y2) {
    }
};

class Figure {
public:
    double cx, cy;     // центр
    Color color;
    Figure(double cx_ = 0, double cy_ = 0, Color c = Color::None) : cx(cx_), cy(cy_), color(c) {}
    virtual ~Figure() = default;
    virtual double area() const = 0;
    virtual Rect boundingRect() const = 0;
    virtual std::string typeName() const = 0;
};