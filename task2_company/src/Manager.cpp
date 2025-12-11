#include "Manager.h"
#include "Team.h"
#include "Worker.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <random>

Manager::Manager(const std::string& name, int id_) : Employee(name), id(id_) {}

void Manager::info() const {
    std::cout << name_ << " (Manager) \n";
}

void Manager::receiveCommand(int bossSeed) {
    if (!team) return;
    int seed = bossSeed + id;
    std::srand(seed);
    int maxTasks = static_cast<int>(team->workers.size());
    int tasksCount = std::rand() % (maxTasks + 1); // 0..maxTasks
    const char types[3] = { 'A','B','C' };

    // gather indices of free workers
    std::vector<int> freeIdx;
    for (int i = 0; i < team->workers.size(); ++i) {
        if (team->workers[i]->task.empty()) freeIdx.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(freeIdx.begin(), freeIdx.end(), g);
    int assign = std::min((int)freeIdx.size(), tasksCount);
    for (int k = 0; k < assign; ++k) {
        int t = std::rand() % 3;
        Worker* w = team->workers[freeIdx[k]];
        w->task = std::string(1, types[t]);
        std::cout << "Assigned task \"" << types[t] << "\" to " << w->name() << "\n";
    }
}