#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct BSTnode{
    int key;
    BSTnode* left;
    BSTnode* right;

    BSTnode(int nKey) {
        key = nKey;
    }
};

class BST{
    private:
        BSTnode* root;

    public:
        BST();
        void addNode(int key);
        BSTnode* findNode(int key);
        void printTree(BSTnode*root, int space);
        BSTnode* getRoot() { return root; }
};

#endif