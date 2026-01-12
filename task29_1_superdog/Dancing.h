#pragma once
#include "Talent.h"

class Dancing : public Talent {
public:
    std::string name() const override {
        return "умеет танцевать";
    }
};