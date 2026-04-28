#ifndef TREECHECK_TREE_H
#define TREECHECK_TREE_H

class TreeNode;

class Tree {
    public:
        Tree();
        ~Tree();
        void addValue(int value);
        void printTree();
        int getMin();
        int getMax();
        bool isBalanced();
        float getAverage();
        void printTreeInfo();
        void searchElement(int target);
        bool containsSubtree(Tree* otherTree);
        TreeNode* getRoot(); // Hilfsfunktion

    private:
        TreeNode* root;

};


#endif //TREECHECK_TREE_H
