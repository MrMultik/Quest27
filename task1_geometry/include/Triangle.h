#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
    double side;
    Triangle(double cx, double cy, double side, Color c = Color::None);
    double area() const override;
    Rect boundingRect() const override;
    std::string typeName() const override { return "Triangle"; }
};