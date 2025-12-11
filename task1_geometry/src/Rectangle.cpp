#include "Rectangle.h"

Rectangle::Rectangle(double cx, double cy, double w_, double h_, Color c) : Figure(cx, cy, c), w(w_), h(h_) {}

double Rectangle::area() const {
    return w * h;
}

Rect Rectangle::boundingRect() const {
    return Rect(cx - w / 2.0, cy - h / 2.0, cx + w / 2.0, cy + h / 2.0);
}