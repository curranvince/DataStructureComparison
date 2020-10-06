#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct Hnode
{
    int key;
    struct Hnode* next;

    Hnode() {key = 0; next = 0;}
    Hnode(int nKey) {key = nKey; next = 0;}
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)
    Hnode** table;          // Pointer to an array containing buckets
    int insertCollisions;
    int searchCollisions;

    //Hnode* next;

public:
    HashTable();
    HashTable(int bsize);  // Constructor
    //~HashTable();

    // inserts a key into hash table
    void insertItem(int key);

    // hash function to map values to key
    int hashFunction(int key) {return key%tableSize;}

    void printTable();

    void resetInsertCollisions();
    void resetSearchCollisions();
    int getInsertCollisions();
    int getSearchCollisions();

    Hnode* searchItem(int key);
};

#endif
