#include <iostream>

#include "hash.hpp"

using namespace std;

int main() {
    HashTable newTable(20);
    
    newTable.insertItem(30);
    newTable.insertItem(10);
    newTable.insertItem(40);
    newTable.insertItem(20);
    newTable.insertItem(130);
    newTable.insertItem(110);
    newTable.insertItem(120);
    newTable.insertItem(90);
    newTable.insertItem(80);
    newTable.insertItem(70);
    newTable.insertItem(60);
    newTable.insertItem(50);
    newTable.insertItem(11);
    newTable.insertItem(170);
    newTable.insertItem(140);

    cout << newTable.searchItem(90) << endl;
    cout << newTable.searchItem(40) << endl;
    cout << newTable.searchItem(170) << endl;

    cout << "Num Collisions: " << newTable.getNumOfCollision() << endl;
    
    newTable.printTable();
}