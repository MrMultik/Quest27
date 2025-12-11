#include "Square.h"

Square::Square(double cx, double cy, double a_, Color c) : Figure(cx, cy, c), a(a_) {}

double Square::area() const {
    return a * a;
}

Rect Square::boundingRect() const {
    double h = a / 2.0;
    return Rect(cx - h, cy - h, cx + h, cy + h);
}