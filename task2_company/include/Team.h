#pragma once
#include <vector>
#include <string>
class Worker;
class Manager;

class Team {
public:
    int id;
    Manager* manager = nullptr;
    std::vector<Worker*> workers;
    Team(int id = 0) : id(id) {}
    ~Team();
    void printStatus() const;
};