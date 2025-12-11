#include "Boss.h"
#include <iostream>

Boss::Boss(const std::string& name) : Employee(name) {}

void Boss::info() const {
    std::cout << name_ << " (Boss)\n";
}