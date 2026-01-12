#pragma once
#include "Talent.h"

class Counting : public Talent {
public:
    std::string name() const override {
        return "умеет считать";
    }
};