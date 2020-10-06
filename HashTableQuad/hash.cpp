#include <iostream>
#include <math.h>

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
        int i = index;
        int a = 1;
        while (table[index] != 0) {
            if ((i + pow(a,2)) < tableSize) {
                index = i + pow(a,2);
                a++;
            } else {
                i = 0;
                a = 1;
                index = i + pow(a,2);
                a++;
            }
        }
        table[index] = newNode;
    }
}

void HashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != 0) {
            Hnode* crawl = table[i];
            cout << "[" << i << "] -> " << table[i]->key;
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
        int i = index;
        int a = 1;
        while (table[index] != 0) {
            if ((i + pow(a,2)) < tableSize) {
                index = i + pow(a,2);
                a++;
            } else {
                i = 0;
                a = 1;
                index = i + pow(a,2);
                a++;
            }
        }
        return table[index];
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
