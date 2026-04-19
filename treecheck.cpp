#include <iostream>
#include "TreeNode.h"
#include <fstream>
#include <string>
using namespace std;

TreeNode* readInTree(const string& file);
void printTreeInfo(TreeNode* root);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: treecheck <filename>" << endl;
        return 1;
    }
    string filename = argv[1];
    cout << "Dateiname: " << filename << endl;

    TreeNode* root = readInTree(filename);
    printTreeInfo(root);
    delete root;
    return 0;
}

void printTreeInfo(TreeNode* root) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root->printInOrder();

    cout << endl;
    string avl = "no";
    bool isBalanced = true;
    root->printBalanceOptimized(isBalanced);
    if (isBalanced) {
        avl = "yes";
    }

    int count = 0;
    int sum  = root->getSum(count);

    cout << "AVL: "<<avl <<endl;
    cout <<"min: "<< root->getMin();
    cout <<", max: "<< root->getMax();
    cout <<", avg: "<< double(sum)/double(count) <<endl;
    cout << endl;
}

TreeNode* readInTree(const string& file) {
    ifstream inputFile(file);
    if (!inputFile) {
        cout << "File could not be opened" << endl;
        return nullptr;
    }
    int number;
    inputFile >> number;
    TreeNode* root = new TreeNode(number);
    while (inputFile >> number) {
        TreeNode* node = new TreeNode(number);
        root->addChild(node);
    }
    return root;
}