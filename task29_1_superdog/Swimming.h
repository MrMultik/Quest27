#pragma once
#include "Talent.h"

class Swimming : public Talent {
public:
    std::string name() const override {
        return "умеет плавать";
    }
};