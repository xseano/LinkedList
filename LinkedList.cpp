// LinkedList.cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

// constuctor with member initializtion list (length, first object)
LinkedList::LinkedList(size_t len, Node* first)
    : length(len), first(first)
{
    // empty
}

LinkedList::~LinkedList()
{
    cout << "Deleted list!" << endl;
}

int LinkedList::getLength()
{
    return length;
}

Node* LinkedList::getNext()
{
    return first;
}

// eventually have append function open to multiple data types
void LinkedList::append(int data)
{
    // create new Node object
    Node* nodeObj = new Node();
    // set data properties
    nodeObj->data = data;
    // next increment
    nodeObj->next = first;

    // set latest item
    first = nodeObj;
    // increment list length
    length++;
}

void LinkedList::display()
{
    Node* firstNode = first;
    
    int i = 1;
    do
    {
        cout << i << ": " << first->data << endl;
        i++;
    } while (i < length); // LIST_LEN (100) as set by nodes created in main loop
}