#include <iostream>

#include "linkedList.hpp"

using namespace std;

LinkedList::~LinkedList() {
    LLnode* current = head;
    while (head != NULL) {
        head = head->next;
        delete current;
        current = head;
    }
}

void LinkedList::insertLLnode(int key) {
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        //cout << "adding: " << key << " (HEAD)" << endl;
        head = new LLnode;
        head->key = key;
        head->next = NULL;
    }
    // if it's not empty, append node to end
    else {
        //cout << "adding: " << key << endl;
        LLnode *temp = new LLnode;
        LLnode *newNode = new LLnode;
        newNode->next = NULL;
        newNode->key = key;
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

LLnode* LinkedList::searchLL(int key)
{
// Search until the head is NULL, or we find the country
    LLnode* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

void LinkedList::displayLL() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    LLnode* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->key << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->key << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
