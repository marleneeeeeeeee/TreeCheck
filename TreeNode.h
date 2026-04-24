//
// Created by Marlene Haberhauer on 18.04.26.
//

#ifndef TREECHECK_TREENODE_H
#define TREECHECK_TREENODE_H


class TreeNode {
public:
    TreeNode(int value);
    virtual ~TreeNode();
    int getValue();
    void addChild(TreeNode* nodeToAppend);
    void printInOrder();
    bool printBalance();
    int getHeight();
    int getMin();
    int getMax();
    int printBalanceOptimized(bool &isBalanced);
    int getSum(int &count);
private:
    TreeNode * left;
    TreeNode * right;
    int value;


};


#endif //TREECHECK_TREENODE_H