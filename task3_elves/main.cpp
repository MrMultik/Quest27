#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "include/Branch.h"

// утилитная функция: если строка == "None" (без учёта регистра) -> true
static bool isNoneName(const std::string& s) {
    if (s.empty()) return false;
    std::string t;
    for (char ch : s) t.push_back(std::tolower((unsigned char)ch));
    return t == "none";
}

int main() {
    std::srand((unsigned)std::time(nullptr));
    Branch* root = new Branch(nullptr);

    std::cout << "=== Task 3: Elves village (recursive branch tree) ===\n\n";
    std::cout << "Building tree automatically (big branches: 3..5, mid branches: 2..3)...\n";
    root->buildRandom(3, 5, 2, 3);

    // collect houses
    std::vector<Branch*> houses;
    root->collectHouses(houses);
    std::cout << "Total houses (big + mid): " << houses.size() << "\n\n";

    std::cout << "You will be prompted for each house:\n"
        << "  - press ENTER to accept auto-generated name\n"
        << "  - type a name to set it\n"
        << "  - type 'None' to leave the house empty\n\n";

    // auto-generate names first
    for (size_t i = 0; i < houses.size(); ++i) {
        houses[i]->elfName = "Elf_" + std::to_string(1000 + (std::rand() % 9000));
    }

    // prompt user for optional overrides
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (size_t i = 0; i < houses.size(); ++i) {
        std::string input;
        std::cout << "House #" << (i + 1) << " current name = " << houses[i]->elfName
            << "   (enter to keep, type new name or 'None' to skip): ";
        std::getline(std::cin, input);
        if (input.empty()) {
            // keep auto name
        }
        else if (isNoneName(input)) {
            houses[i]->elfName = "None";
        }
        else {
            houses[i]->elfName = input;
        }
    }

    std::cout << "\nFinal village layout:\n\n";
    root->printTree(1);

    std::cout << "\nNow you can search for an elf by exact name (case-sensitive).\n";
    std::cout << "Enter the elf name (or empty line to finish): ";
    std::string query;
    std::getline(std::cin, query);
    if (query.empty()) {
        std::cout << "No query entered. Exiting.\n";
        delete root;
        return 0;
    }

    Branch* found = root->findElf(query);
    if (!found) {
        std::cout << "Elf '" << query << "' not found in the village.\n";
        delete root;
        return 0;
    }

    // Determine top big-branch for the found node
    Branch* top = found->getTopBranch();
    if (!top) {
        // If the found node is the big branch itself (getTopBranch returns this),
        // then top should be found (it is big), but our getTopBranch implementation
        // returns this for big nodes. However if somehow top==nullptr, treat found as top.
        top = found;
    }

    // Count elves on that big branch: big branch's own elf (if not None) + mid children elves
    int totalOnBranch = 0;
    if (!top->elfName.empty() && !isNoneName(top->elfName)) totalOnBranch++;
    for (Branch* m : top->children) {
        if (!m->elfName.empty() && !isNoneName(m->elfName)) totalOnBranch++;
    }

    std::cout << "Elf '" << query << "' found.\n";
    std::cout << "Total elves on the same big branch (including target): " << totalOnBranch << "\n";
    std::cout << "Neighbors (excluding target): " << (std::max(0, totalOnBranch - 1)) << "\n";

    delete root;
    return 0;
}