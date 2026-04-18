//
// Created by Marlene Haberhauer on 18.04.26.
//

#include "TreeNode.h"

#include <iostream>
#include <ostream>

TreeNode::TreeNode(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

int TreeNode::getValue() {
    return this->value;
}

void TreeNode::addChild(TreeNode *nodeToAppend) {
    if (this->value == nodeToAppend->getValue()) {
        std::cout << "Already exists!" << std::endl;
        return;
    }
    if (nodeToAppend->getValue()<this->value) {
        if (this->left!=nullptr) {
            this->left->addChild(nodeToAppend);
            return;
        }
        this->left = nodeToAppend;
    }
    if (nodeToAppend->getValue() > this->value) {
        if (this->right!=nullptr) {
            this->right->addChild(nodeToAppend);
            return;
        }
        this->right = nodeToAppend;
    }
}

void TreeNode::printInOrder() {
    if (this->left!=nullptr) {
        this->left->printInOrder();
    }
    std::cout << this->value << " ";
    if (this->right!=nullptr) {
        this->right->printInOrder();
    }
}
int TreeNode::printBalanceOptimized(bool &isBalanced) {
    int heightLeft = 0;
    int heightRight = 0;
    if (left != nullptr)
        heightLeft = left->printBalanceOptimized(isBalanced);
    if (right != nullptr)
        heightRight = right->printBalanceOptimized(isBalanced);
    int balance = heightRight - heightLeft;
    std::cout << "bal(" << value << ") = " << balance;
    if (balance > 1 || balance < -1) {
        std::cout << " (AVL violation!)";
        isBalanced = false;
    }
    std::cout << std::endl;
    return std::max(heightLeft, heightRight) + 1;
}

int TreeNode::getAverage(int &count) {
    int sum = this->value;
    if (left != nullptr) {
        sum += left->getAverage(count);
    }
    if (right != nullptr) {
        sum += right->getAverage(count);
    }
    count++;
    return sum;
}

bool TreeNode::printBalance() {
    int heightLeft = 0;
    int heightRight = 0;
    bool leftBalance = true;
    bool rightBalance = true;
    bool balanced = true;
    if (this->left!=nullptr) {
       heightLeft = this->left->getHeight();
        leftBalance = left->printBalance();
    }
    if (this->right!=nullptr) {
        heightRight = this->right->getHeight();
        rightBalance = right->printBalance();
    }
    int balance = heightRight - heightLeft;
    std::cout <<"bal("<< this->value <<") = " << balance;
    if (balance > 1 || balance < -1) {
        std::cout << "(AVL violation!)";
        balanced = false;
    }
    std::cout << std::endl;
    return rightBalance && leftBalance && balanced;
}


int TreeNode::getHeight() {
    if (left==nullptr && right==nullptr) {
        return 1;
    }
    if (left!=nullptr && right!=nullptr) {
        return std::max(left->getHeight(), right->getHeight())+1;
    }
    if (left!=nullptr) {
        return left->getHeight()+1;
    }
    return right->getHeight()+1;
}

int TreeNode::getMin() {
    if (left==nullptr) {
        return value;
    }
    return left->getMin();
}

int TreeNode::getMax() {
    if (right==nullptr) {
        return value;
    }
    return right->getMax();
}

TreeNode::~TreeNode() {
    if (left!=nullptr) {
        delete left;
    }
    if (right!=nullptr) {
        delete right;
    }
}


