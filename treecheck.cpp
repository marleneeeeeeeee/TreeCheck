#include <iostream>
#include "TreeNode.h"
#include <fstream>
#include <string>
#include "Tree.h"

using namespace std;
void readInTree(const string& file, Tree* tree);

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        cout << "Usage: treecheck <filename-tree> [<filename-subtree>]" << endl;
        return 1;
    }

    string filename = argv[1];
    cout << "Dateiname: " << filename << endl;

    Tree* mainTree = new Tree();
    readInTree(argv[1], mainTree);

    if (argc == 2) {
        // statistics
        mainTree->printTreeInfo();
    }
    else if (argc == 3) {
        Tree* subTree = new Tree();

        // read subtree values
        ifstream subFile(argv[2]);
        int val;
        vector<int> subValues;
        while (subFile >> val) {
            subTree->addValue(val);
            subValues.push_back(val);
        }

        if (subValues.size() == 1) {
            // search int
            mainTree->searchElement(subValues[0]);
        } else if (subValues.size() > 1) {
            // search subtree
            if (mainTree->containsSubtree(subTree)) {
                cout << "Subtree found" << endl;
            } else {
                cout << "Subtree not found!" << endl;
            }
        }
        delete subTree;
    }

    delete mainTree;
    return 0;
}

void readInTree(const string& file, Tree* tree) {
    ifstream inputFile(file);
    if (!inputFile) {
        cout << "File could not be opened" << endl;
        return;
    }
    int number;
    while (inputFile >> number) {
        tree->addValue(number);
    }
}
