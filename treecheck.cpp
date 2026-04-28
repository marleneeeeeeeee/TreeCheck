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
        // Teil 1: Statistik
        mainTree->printTreeInfo();
    }
    // ... im main-Block (argc == 3) ...
    else if (argc == 3) {
        Tree* subTree = new Tree();

        // Wir lesen die Subtree-Werte ein
        ifstream subFile(argv[2]);
        int val;
        vector<int> subValues;
        while (subFile >> val) {
            subTree->addValue(val);
            subValues.push_back(val);
        }

        if (subValues.size() == 1) {
            // Fall: Einfache Suche
            mainTree->searchElement(subValues[0]);
        } else if (subValues.size() > 1) {
            // Fall: Subtree Suche
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
/*
    Tree* tree = new Tree();
    readInTree(filename, tree);
    tree->printTreeInfo();
    delete tree;
    return 0;
    */
}

/*
int main() {
    cout << "Test Start" << endl;
    Tree* tree = new Tree();
    tree->addValue(10);
    tree->addValue(5);
    tree->addValue(15);
    cout << "Werte hinzugefügt" << endl;
    tree->printTreeInfo();
    cout << "Info ausgegeben" << endl;
    delete tree;
    cout << "Test Ende" << endl;
    return 0;
}
*/
void readInTree(const string& file, Tree* tree) {
    ifstream inputFile(file);
    if (!inputFile) {
        cout << "File could not be opened" << endl;
        return;
    }
    int number;
//    inputFile >> number;
    while (inputFile >> number) {
        tree->addValue(number);
    }
}
