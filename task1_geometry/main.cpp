#include <iostream>
#include <string>
#include <memory>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"

static Color readColor(int v) {
    if (v == 1) return Color::Red;
    if (v == 2) return Color::Green;
    if (v == 3) return Color::Blue;
    return Color::None;
}

int main() {
    std::cout << "=== Task 1: Geometry ===\n";
    std::cout << "Commands:\n";
    std::cout << "  circle  -> then enter: cx cy r color(0-none,1-red,2-green,3-blue)\n";
    std::cout << "  square  -> then enter: cx cy side color\n";
    std::cout << "  triangle-> then enter: cx cy side color\n";
    std::cout << "  rectangle-> then enter: cx cy width height color\n";
    std::cout << "  exit\n";

    std::string cmd;
    while (true) {
        std::cout << "cmd> ";
        if (!(std::cin >> cmd)) break;
        if (cmd == "exit") break;

        if (cmd == "circle") {
            double cx, cy, r; int col;
            std::cout << "Enter: cx cy r color: ";
            std::cin >> cx >> cy >> r >> col;
            Circle f(cx, cy, r, readColor(col));
            std::cout << "Type = " << f.typeName() << ", Area = " << f.area() << "\n";
            Rect rc = f.boundingRect();
            std::cout << "Bounding rect: (" << rc.xmin << "," << rc.ymin << ") - (" << rc.xmax << "," << rc.ymax << ")\n";
        }
        else if (cmd == "square") {
            double cx, cy, a; int col;
            std::cout << "Enter: cx cy side color: ";
            std::cin >> cx >> cy >> a >> col;
            Square f(cx, cy, a, readColor(col));
            std::cout << "Type = " << f.typeName() << ", Area = " << f.area() << "\n";
            Rect rc = f.boundingRect();
            std::cout << "Bounding rect: (" << rc.xmin << "," << rc.ymin << ") - (" << rc.xmax << "," << rc.ymax << ")\n";
        }
        else if (cmd == "triangle") {
            double cx, cy, a; int col;
            std::cout << "Enter: cx cy side color: ";
            std::cin >> cx >> cy >> a >> col;
            Triangle f(cx, cy, a, readColor(col));
            std::cout << "Type = " << f.typeName() << ", Area = " << f.area() << "\n";
            Rect rc = f.boundingRect();
            std::cout << "Bounding rect: (" << rc.xmin << "," << rc.ymin << ") - (" << rc.xmax << "," << rc.ymax << ")\n";
        }
        else if (cmd == "rectangle") {
            double cx, cy, w, h; int col;
            std::cout << "Enter: cx cy width height color: ";
            std::cin >> cx >> cy >> w >> h >> col;
            Rectangle f(cx, cy, w, h, readColor(col));
            std::cout << "Type = " << f.typeName() << ", Area = " << f.area() << "\n";
            Rect rc = f.boundingRect();
            std::cout << "Bounding rect: (" << rc.xmin << "," << rc.ymin << ") - (" << rc.xmax << "," << rc.ymax << ")\n";
        }
        else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
    return 0;
}