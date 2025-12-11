#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double cx, double cy, double side_, Color c) : Figure(cx, cy, c), side(side_) {}

double Triangle::area() const {
    return (side * side * std::sqrt(3.0)) / 4.0;
}

Rect Triangle::boundingRect() const {
    double h = side * std::sqrt(3.0) / 2.0;
    double halfW = side / 2.0;
    // centroid approx: use 2/3 of height from centroid to top: safe halfHeight
    double halfH = h * 2.0 / 3.0;
    return Rect(cx - halfW, cy - halfH, cx + halfW, cy + halfH);
}