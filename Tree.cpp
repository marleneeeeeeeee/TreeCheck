//
// Created by Marlene Haberhauer on 24.04.26.
//

#include "Tree.h"
#include "TreeNode.h"
#include "iostream"

Tree::Tree() {
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
    bool balance;
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
    int avg  = getAverage();
    cout << "AVL: "<<avl <<endl;
    cout <<"min: "<< getMin() <<endl;
    cout <<", max: "<< getMax() <<endl;
    cout <<", avg: "<< avg <<endl;
    cout << endl;
}

Tree::~Tree() {

}


