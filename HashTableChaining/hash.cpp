#include <iostream>

#include "hash.hpp"

using namespace std;

HashTable::HashTable() {
    tableSize = 10;
    insertCollisions = 0;
    searchCollisions = 0;
    table = new Hnode *[10];
    for (int i = 0; i < tableSize; i++) {
        table[i] = 0;
    }
}

HashTable::HashTable(int bsize) {
    tableSize = bsize;
    insertCollisions = 0;
    searchCollisions = 0;
    table = new Hnode *[bsize];
    for (int i = 0; i < tableSize; i++) {
        table[i] = 0;
    }
}

void HashTable::insertItem(int key) {
    Hnode* newNode = new Hnode(key);
    int index = hashFunction(key);
    if (table[index] == 0) {
        table[index] = newNode;
    } else {
        insertCollisions++;
        Hnode* curr = table[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void HashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != 0) {
            Hnode* crawl = table[i];
            cout << "[" << i << "] -> ";
            while (crawl != NULL) {
                cout << crawl->key << " -> ";
                crawl = crawl->next;
            }
            cout << "NULL" << endl;
        } else {
            cout << "[" << i << "] -> EMPTY" << endl;
        }
    }
}

Hnode* HashTable::searchItem(int key) {
    int index = hashFunction(key);
    if (table[index] == 0) {
        return 0;
    } else if (table[index]->key == key) {
        return table[index];
    } else {
        searchCollisions++;
        Hnode* curr = table[index];
        while (curr != 0) {
            if (curr->key == key) {return curr;}
            else {curr = curr->next;}
        }
    }
    return 0;
}

void HashTable::resetInsertCollisions() {
    insertCollisions = 0;
}   

void HashTable::resetSearchCollisions() {
    searchCollisions = 0;
}  

int HashTable::getInsertCollisions() {
    return insertCollisions;
}  

int HashTable::getSearchCollisions() {
    return searchCollisions;
}  
