#pragma once
#include <string>

class Employee {
protected:
    std::string name_;
public:
    Employee(const std::string& name = "") : name_(name) {}
    virtual ~Employee() = default;
    std::string name() const { return name_; }
    virtual void info() const = 0;
};