#include "Circle.h"
#include <cmath>

Circle::Circle(double cx, double cy, double r_, Color c) : Figure(cx, cy, c), r(r_) {}

double Circle::area() const {
    const double PI = 4.0 * atan(1.0);
    return PI * r * r;
}

Rect Circle::boundingRect() const {
    return Rect(cx - r, cy - r, cx + r, cy + r);
}