// LinkedList.cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

// constuctor with member initializtion list (length, first object)
LinkedList::LinkedList(size_t len, Node* first)
    : length(len), head(first)
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
    return head;
}

// eventually have append function open to multiple data types
void LinkedList::append(int data)
{
    // create new Node object
    Node* nodeObj = new Node();
    // set data properties
    nodeObj->data = data;
    // next increment
    nodeObj->next = head;

    // set latest item
    head = nodeObj;
    // increment list length
    length++;
}

void LinkedList::display()
{
    Node* firstNode = head;
    
    int i = 1;
    do
    {
        cout << i << ": " << head->data << endl;
        i++;
    } while (i < length); // LIST_LEN (100) as set by nodes created in main loop
}