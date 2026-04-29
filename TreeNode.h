#ifndef TREECHECK_TREENODE_H
#define TREECHECK_TREENODE_H
#include <vector>

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
    bool findPath(int target, std::vector<int>& path);
    TreeNode* findNode(int target);
    bool containsSequence(const std::vector<int>& sequence, int index);

private:
    TreeNode * left;
    TreeNode * right;
    int value;


};


#endif //TREECHECK_TREENODE_H
