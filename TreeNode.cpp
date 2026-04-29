#include "TreeNode.h"

#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>

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
        delete nodeToAppend;
        return;
    }
    if (nodeToAppend->getValue()<this->value) {
        if (this->left!=nullptr) {
            this->left->addChild(nodeToAppend);
            return;
        }
        this->left = nodeToAppend;
    }
    else if (nodeToAppend->getValue() > this->value) {
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
//    std::cout << std::endl;
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

int TreeNode::getSum(int &count) {
    int sum = this->value;
    if (left != nullptr) {
        sum += left->getSum(count);
    }
    if (right != nullptr) {
        sum += right->getSum(count);
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

bool TreeNode::findPath(int target, std::vector<int>& path) {
    path.push_back(this->value); // saves the nodes of the path in a vector

    if (this->value == target) {
            return true;
    }

    if (target < this->value && left != nullptr) {
        if (left->findPath(target, path)) {
                return true;
        }
    } else if (target > this->value && right != nullptr) {
        if (right->findPath(target, path)) {
                return true;
        }
    }

    path.pop_back(); // deletes number if its a dead end
    return false;
}

// returns the node of the tree that matches the target
// so the search can start at the root of the subtree
TreeNode* TreeNode::findNode(int target) {
    if (this->value == target) {
            return this;
    }
    if (target < this->value && left != nullptr) {
            return left->findNode(target);
    }
    if (target > this->value && right != nullptr) {
            return right->findNode(target);
    }

    return nullptr;
}

bool TreeNode::containsSequence(const std::vector<int>& sequence, int index) {
    // found all values
    if (index >= sequence.size()) {
            return true;
    }

    int target = sequence[index];

    // current node is in the subtree sequence
    if (this->value == target) {
        if (index + 1 == sequence.size()) {
                return true;
        }

        bool foundLeft = false;
        bool foundRight = false;
        if(left != nullptr) {
            foundLeft = left->containsSequence(sequence, index + 1);
        }
        if(right != nullptr) {
            foundRight = right->containsSequence(sequence, index + 1);
        }

        return foundLeft || foundRight;
    }

    // current node is not in the sequence
    if (target < this->value && left != nullptr) {
        return left->containsSequence(sequence, index);
    }
    else if (target > this->value && right != nullptr) {
        return right->containsSequence(sequence, index);
    }

    return false;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}
