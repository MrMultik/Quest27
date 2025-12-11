#pragma once
#include "Figure.h"

class Square : public Figure {
public:
    double a;
    Square(double cx, double cy, double a, Color c = Color::None);
    double area() const override;
    Rect boundingRect() const override;
    std::string typeName() const override { return "Square"; }
};