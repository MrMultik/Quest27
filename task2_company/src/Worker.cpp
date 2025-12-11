#include "Worker.h"
#include <iostream>

Worker::Worker(const std::string& name) : Employee(name), task("") {}

void Worker::info() const {
    if (task.empty()) std::cout << name_ << " free\n";
    else std::cout << name_ << " performs task \"" << task << "\"\n";
}