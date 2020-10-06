#include <iostream>

#include "BST.hpp"

using namespace std;

BST::BST() {
    root = NULL;
}

BSTnode* createNode(int key) {
  BSTnode* newNode = new BSTnode(key);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

BSTnode* addNodeHelper(BSTnode* currNode, int key) {
  if (currNode == NULL) {
    return createNode(key);
  } else if (currNode->key < key) {
    currNode->right = addNodeHelper(currNode->right, key);
  }  else if (currNode->key > key) {
    currNode->left = addNodeHelper(currNode->left, key);
  }
  return currNode;
}

void BST::addNode(int key) {
  root = addNodeHelper(root, key);
  cout << "Adding: " << key << endl;
}

BSTnode* BST::findNode(int key) {
  BSTnode* firstNode = root;
  if (key == firstNode->key) {
    return firstNode;
  } else {
    while(firstNode != NULL) {
      if (key < firstNode->key)  {
        firstNode = firstNode->left; //go left if key is less
      } else if  (key > firstNode->key) {
        firstNode = firstNode->right; //go right if key is more
      } else {
        return firstNode;
      }
    }
    return firstNode;
  }
}

void BST::printTree(BSTnode *root, int space)
{
    int COUNT = 10;
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    printTree(root->left, space);
}