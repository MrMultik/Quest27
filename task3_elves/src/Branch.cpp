#include "Branch.h"
#include <cstdlib>
#include <iostream>

Branch::Branch(Branch* parent_) : parent(parent_), elfName("None") {}

Branch::~Branch() {
    for (Branch* c : children) delete c;
}

void Branch::buildRandom(int bigMin, int bigMax, int midMin, int midMax) {
    // Only valid when called on root (parent == nullptr), but works otherwise too.
    if (bigMin > bigMax) bigMax = bigMin;
    if (midMin > midMax) midMax = midMin;

    // If this is root -> create big branches
    if (parent == nullptr) {
        int bigCount = bigMin + (std::rand() % (bigMax - bigMin + 1));
        for (int i = 0; i < bigCount; ++i) {
            Branch* big = new Branch(this);
            // For each big branch create mid branches
            int midCount = midMin + (std::rand() % (midMax - midMin + 1));
            for (int j = 0; j < midCount; ++j) {
                Branch* mid = new Branch(big);
                big->children.push_back(mid);
            }
            children.push_back(big);
        }
    }
    else {
        // If called on non-root, do nothing (construction done above)
    }
}

void Branch::collectHouses(std::vector<Branch*>& out) {
    // houses are big branches and their mid children
    for (auto b : children) {
        out.push_back(b); // big branch
        for (auto m : b->children) out.push_back(m); // mid branches
    }
}

void Branch::printTree(int treeIndex) const {
    // We print root label, then iterate big branches with indices, then mid branches
    if (parent != nullptr) {
        // Not root: we only support calling this on root for full layout
        std::cout << "printTree should be called on root\n";
        return;
    }

    std::cout << "Tree " << treeIndex << ".\n\n";
    for (size_t i = 0; i < children.size(); ++i) {
        const Branch* big = children[i];
        // Big label 1.i
        std::cout << "  Big " << treeIndex << "." << (i + 1) << " - "
            << (big->elfName.empty() ? "None" : big->elfName) << "\n\n";

        // Middle branches
        for (size_t j = 0; j < big->children.size(); ++j) {
            const Branch* mid = big->children[j];
            std::cout << "    Middle " << treeIndex << "." << (i + 1) << "." << (j + 1)
                << " - " << (mid->elfName.empty() ? "None" : mid->elfName) << "\n";
        }
        std::cout << "\n";
    }
}

Branch* Branch::findElf(const std::string& name) {
    if (elfName == name) return this;
    for (Branch* c : children) {
        Branch* found = c->findElf(name);
        if (found) return found;
    }
    return nullptr;
}

Branch* Branch::getTopBranch() {
    if (parent == nullptr) return nullptr; // root
    if (parent->parent == nullptr) return this; // parent is root -> this is big
    return parent->getTopBranch();
}