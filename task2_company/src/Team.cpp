#include "Team.h"
#include "Worker.h"
#include "Manager.h"
#include <iostream>

Team::~Team() {
    for (auto w : workers) delete w;
    // manager deleted by caller (Company/main)
}

void Team::printStatus() const {
    std::cout << "Team " << id;
    if (manager) std::cout << " - Manager " << manager->name();
    std::cout << "\n";
    for (auto w : workers) {
        std::cout << "    ";
        w->info();
    }
    std::cout << "----\n";
}