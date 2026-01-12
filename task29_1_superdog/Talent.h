#pragma once
#include <string>

class Talent {
public:
    virtual ~Talent() = default;
    virtual std::string name() const = 0;
};