#pragma once
#include "Employee.h"
#include <string>

class Worker : public Employee {
public:
    std::string task; // empty = free
    Worker(const std::string& name = "");
    void info() const override;
};