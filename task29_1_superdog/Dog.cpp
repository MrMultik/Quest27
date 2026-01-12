#include "Dog.h"

Dog::Dog(const std::string& name) : name(name) {}

void Dog::addTalent(std::unique_ptr<Talent> talent) {
    talents.push_back(std::move(talent));
}

void Dog::show_talents() const {
    std::cout << "Собака по имени " << name << " обладает следующими талантами:\n";

    if (talents.empty()) {
        std::cout << "  (талантов нет)\n";
        return;
    }

    for (const auto& t : talents) {
        std::cout << "  - " << t->name() << '\n';
    }
}