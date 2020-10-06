#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

using namespace std;

struct LLnode
{
    int key;
    LLnode* next;
};

class LinkedList
{
    private:
        LLnode* head;

    public:
        LinkedList() {head = NULL;}
        ~LinkedList();
        void insertLLnode(int key);
        LLnode* searchLL(int key);
        void displayLL();
};

#endif
