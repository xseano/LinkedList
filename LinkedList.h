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

		void displayList(); // display nodes

		int getCurrentSize(); // size or length of the data structure

		bool isEmpty(); // is the data structure empty

		void addToBack(T data); // add tail node
		void addToFront(T data); // add head node

		void removeFromBack(); // remove tail node
		void removeFromFront(); // remove head node

		bool contains(T data); // does the data structure have this data
		int getFrequencyOf(T data); // how many times is the data in the data structure
		vector<T> toVector(); // return data in a vector (e.g. to print out)
};

#include "LinkedList.cpp"

#endif
