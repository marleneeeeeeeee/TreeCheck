#include "Tree.h"
#include "TreeNode.h"
#include "iostream"
#include <vector>

Tree::Tree() {
    root = nullptr;
}

using namespace std;
void Tree::addValue(int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    root->addChild(new TreeNode(value));
}

void Tree::printTree() {
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return;
    }
    root->printInOrder();
}

int Tree::getMin() {
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return -1;
    }
    return root->getMin();
}

int Tree::getMax() {
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return -1;
    }
    return root->getMax();
}

float Tree::getAverage() {
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return -1;
    }
    int count = 0;
    int sum = root->getSum(count);
    return (float)sum/(float)count;
}

bool Tree::isBalanced() {
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return false;
    }
    std::cout << std::endl;
    bool balance = true;
    root->printBalanceOptimized(balance);
    return balance;
}

void Tree::printTreeInfo() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    this->printTree();
    string avl = "no";
    if (isBalanced()) {
        avl = "yes";
    }
    cout << endl;
    float avg  = getAverage();
    cout << "AVL: "<< avl <<endl;
    cout <<"min: "<< getMin() << ", max: " << getMax() << ", avg: " << avg << endl;
}

void Tree::searchElement(int target) {
    if (root == nullptr) {
        std::cout << target << " not found!" << std::endl;
        return;
    }

    std::vector<int> path;

    if (root->findPath(target, path)) {
        std::cout << target << " found ";

        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if(i == path.size() - 1) {
                std::cout << std::endl;
            } else {
                cout << ", ";
            }
        }
    } else {
        std::cout << target << " not found!" << std::endl;
    }
}

bool Tree::containsSubtree(Tree* otherTree) {
    if (otherTree->root == nullptr) return true;

    // finds root of subtree in main tree
    TreeNode* startNode = root->findNode(otherTree->root->getValue());
    if (startNode == nullptr) {
            return false;
    }

    return startNode->compareStructure(otherTree->root);
}

TreeNode* Tree::getRoot() {
    return root;
}


Tree::~Tree() {
    if (root != nullptr) {
        delete root;
    }
}
