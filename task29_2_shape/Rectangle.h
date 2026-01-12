#pragma once
#include "Shape.h"

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}

    double square() const override {
        return w * h;
    }

    BoundingBoxDimensions dimensions() const override {
        return { w, h };
    }

    std::string type() const override {
        return "Rectangle";
    }
};