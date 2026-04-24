#include <iostream>
#include "TreeNode.h"
#include <fstream>
#include <string>
#include "Tree.h"

using namespace std;
void readInTree(const string& file, Tree* tree);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: treecheck <filename>" << endl;
        return 1;
    }
    string filename = argv[1];
    cout << "Dateiname: " << filename << endl;

    Tree* tree = new Tree();
    readInTree(filename, tree);
    tree->printTreeInfo();
    delete tree;
    return 0;
}

void readInTree(const string& file, Tree* tree) {
    ifstream inputFile(file);
    if (!inputFile) {
        cout << "File could not be opened" << endl;
        return;
    }
    int number;
    inputFile >> number;
    while (inputFile >> number) {
        tree->addValue(number);
    }
}