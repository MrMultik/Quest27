#pragma once
#include "Shape.h"
#include <cmath>
#include <numbers>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle : public Shape {
    double r;
public:
    explicit Circle(double r) : r(r) {}

    double square() const override {
        return M_PI * r * r;
    }

    BoundingBoxDimensions dimensions() const override {
        return { 2 * r, 2 * r };
    }

    std::string type() const override {
        return "Circle";
    }
};