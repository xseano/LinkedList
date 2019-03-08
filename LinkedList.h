// LinkedList.h
// oberoi, sean
// ssoberoi

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define LIST_LEN 100

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    public:
        LinkedList(size_t len, Node* first);
        ~LinkedList();

        void append(int data);
        void display();
        int getLength();
        Node* getNext();
        
    private:
        Node* head;
        int length;
};

#endif
