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
	public:
		LinkedList();
		~LinkedList();

		void clear(); // clear the data structure

		int getCurrentSize(); // size or length of the data structure

		bool isEmpty(); // is the data structure empty

		void addNode(T data); // add node
		void removeNode(T data); // remove node
		
		vector<T> toVector(); // return data in a vector (e.g. to print out)
};

#include "LinkedList.cpp"

#endif
