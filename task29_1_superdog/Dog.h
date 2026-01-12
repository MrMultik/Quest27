#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Talent.h"

class Dog {
    std::string name;
    std::vector<std::unique_ptr<Talent>> talents;

public:
    explicit Dog(const std::string& name);

    void addTalent(std::unique_ptr<Talent> talent);
    void show_talents() const;
};