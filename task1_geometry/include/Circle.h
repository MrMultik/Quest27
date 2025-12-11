#pragma once
#include "Figure.h"

class Circle : public Figure {
public:
    double r;
    Circle(double cx, double cy, double r, Color c = Color::None);
    double area() const override;
    Rect boundingRect() const override;
    std::string typeName() const override { return "Circle"; }
};