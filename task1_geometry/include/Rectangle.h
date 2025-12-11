#pragma once
#include "Figure.h"

class Rectangle : public Figure {
public:
    double w, h;
    Rectangle(double cx, double cy, double w, double h, Color c = Color::None);
    double area() const override;
    Rect boundingRect() const override;
    std::string typeName() const override { return "Rectangle"; }
};