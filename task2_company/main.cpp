#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Team.h"
#include "Manager.h"
#include "Worker.h"
#include "Boss.h"

int main() {
    std::cout << "=== Task 2: Company simulation ===\n";
    int teamsCount = 0, workersPerTeam = 0;
    std::cout << "Enter number of teams: ";
    std::cin >> teamsCount;
    std::cout << "Enter number of workers per team: ";
    std::cin >> workersPerTeam;

    // build company (simple owner-constructed structure)
    std::vector<Team*> teams;
    teams.reserve(teamsCount);
    for (int i = 0; i < teamsCount; ++i) {
        Team* t = new Team(i + 1);
        // manager
        Manager* m = new Manager(std::string("Manager_") + std::to_string(i + 1), i + 1);
        m->team = t;
        t->manager = m;
        // workers
        for (int j = 0; j < workersPerTeam; ++j) {
            Worker* w = new Worker(std::string("Worker_") + std::to_string(i + 1) + "_" + std::to_string(j + 1));
            t->workers.push_back(w);
        }
        teams.push_back(t);
    }

    Boss boss("Boss_1");
    std::cout << "\nInitial company state:\n";
    for (auto t : teams) t->printStatus();

    // loop: read seeds from boss -> each manager receives command and assigns tasks
    while (true) {
        // check if all busy
        bool allBusy = true;
        for (auto t : teams) {
            for (auto w : t->workers) if (w->task.empty()) { allBusy = false; break; }
            if (!allBusy) break;
        }
        if (allBusy) {
            std::cout << "All workers busy — simulation finished.\n";
            break;
        }

        int seed;
        std::cout << "Enter boss command id (integer), or non-int to quit: ";
        if (!(std::cin >> seed)) break;

        // Each manager receives command
        for (auto t : teams) {
            if (t->manager) {
                std::cout << "Manager " << t->manager->name() << " receives command seed " << seed << "\n";
                t->manager->receiveCommand(seed);
            }
        }

        std::cout << "State after command:\n";
        for (auto t : teams) t->printStatus();
    }

    // cleanup
    for (auto t : teams) {
        delete t->manager;
        delete t;
    }

    return 0;
}