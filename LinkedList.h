// LinkedList.h
// oberoi, sean
// ssoberoi

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
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

	void clear(); // clear the data structure 

	void displayList(); 

	int getCurrentSize(); // size or length of the data structure
	bool isEmpty(); // is the data structure empty

	void add(T data); // add tail node
	void prepend(T data); // add head node

	void pop(); // remove tail node
	void shift(); // remove head node

	bool contains(T data); // does the data structure have this data
	int getFrequencyOf(T data); // how many times is the data in the data structure
	vector<T> toVector(); // return data in a vector (e.g. to print out)
};

#include "LinkedList.cpp"

#endif
