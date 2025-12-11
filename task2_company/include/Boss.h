#pragma once
#include "Employee.h"

class Boss : public Employee {
public:
    Boss(const std::string& name = "");
    void info() const override;
};