#include <iostream>

#include "BST.hpp"

using namespace std;

int main() {
    BST myTree;
    int myArray[] = {29, 6, 38, 31, 6, 32, 500, 532, 18, 53, 5, 1, 17, 20, 4};
    for (int i = 0; i < 15; i++) {
        myTree.addNode(myArray[i]);
    }
    myTree.printTree(myTree.getRoot(), 2);
    return 0;
}