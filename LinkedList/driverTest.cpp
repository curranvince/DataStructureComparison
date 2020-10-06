#include <iostream>

#include "linkedList.hpp"

using namespace std;

int main() {
    LinkedList myList;
    myList.insertLLnode(NULL, 6);
    myList.insertLLnode(myList.searchLL(6), 8);
    myList.insertLLnode(myList.searchLL(8), 4);
    myList.insertLLnode(myList.searchLL(4), 10);
    myList.insertLLnode(myList.searchLL(10), 25);
    myList.insertLLnode(myList.searchLL(25), 2);
    myList.insertLLnode(myList.searchLL(2), 19);
    myList.displayLL();
    return 0;
}