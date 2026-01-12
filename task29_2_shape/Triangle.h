#pragma once
#include "Shape.h"
#include <cmath>

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double square() const override {
        double p = (a + b + c) / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    BoundingBoxDimensions dimensions() const override {
        double area = square();
        double R = (a * b * c) / (4 * area);
        return { 2 * R, 2 * R };
    }

    std::string type() const override {
        return "Triangle";
    }
};