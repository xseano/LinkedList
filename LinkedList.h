// LinkedList.h
// oberoi, sean
// ssoberoi

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
	struct Node
	{
        // Data and next position
		T data;
		Node *next;
        
        // initialization list
		Node(T d, Node *n = 0):data(d), next(n) {}
	};
	
    Node *head;

public:
	LinkedList(Node *h = 0);
	~LinkedList();

    // add obj, append to head, prepend to tail
	void addNode(Node *obj, T data);
	void addToBack(T data);
	void addToFront(T data);

    // pop head / tail nodes
    T removeFromBack();
	T removeFromFront();
    void removeNode(Node *obj);

    // display list
	void display();
	
    // searching for object position within list
    Node *search(T data);
};

#endif
