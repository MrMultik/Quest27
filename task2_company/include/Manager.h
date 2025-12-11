#pragma once
#include "Employee.h"

class Team; // forward

class Manager : public Employee {
public:
    Team* team = nullptr;
    int id = 0;
    Manager(const std::string& name = "", int id = 0);
    void info() const override;
    void receiveCommand(int bossSeed);
};