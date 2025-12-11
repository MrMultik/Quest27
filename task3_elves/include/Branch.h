#pragma once
#include <vector>
#include <string>

class Branch {
public:
    Branch* parent;
    std::vector<Branch*> children;
    std::string elfName; // "None" or empty means empty

    Branch(Branch* parent = nullptr);
    ~Branch();

    // Build tree structure:
    // root -> big branches (count between bigMin..bigMax)
    // each big branch -> mid branches (count between midMin..midMax)
    void buildRandom(int bigMin = 3, int bigMax = 5, int midMin = 2, int midMax = 3);

    // Collect houses (big branches and their mid branches) in traversal order
    void collectHouses(std::vector<Branch*>& out);

    // Recursively print tree with labels (Tree 1, Big 1.i, Middle 1.i.j)
    void printTree(int treeIndex = 1) const;

    // Find branch that contains elf with exact name (returns pointer or nullptr)
    Branch* findElf(const std::string& name);

    // For any node, return the pointer to the big-branch that contains it.
    // If node itself is a big branch, returns that node.
    // If node is root, returns nullptr.
    Branch* getTopBranch();
};