// LinkedList.cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(Node *h)
    : head(h)
{
    //
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node *temp;
	while(head)
    {
		temp = head;
		head = head->next;
        // destroy the head of the list, incrementing until no nodes left
		delete temp;
	}
}

// insert data before obj
template <typename T>
void LinkedList<T>::addNode(Node *obj, T data) 
{ 
	Node *newNode = new Node(data);

	if(!head)
    {
		head = newNode;
		return;
	}

	if(obj == head)
    {
        // already the head so we just add in front
		addToFront(data);
		return;
	}

    // current head node
	Node *curr = head;

	while(curr->next)
    {
		if(curr->next == obj)
        {
			newNode->next = curr->next;
			curr->next = newNode;
			return;
		}

		curr = curr->next;
	}
}

template <typename T>
void LinkedList<T>::addToBack(T data) 
{
	Node *newNode = new Node(data);

	if(!head)
    {
		head = newNode;
		return;
	}

	Node *curr = head;

	while(curr)
    {
		if(!curr->next)
        {
			curr->next = newNode;
			return;
		}
		curr = curr->next;
	}
}

template <typename T>
void LinkedList<T>::addToFront(T data)
{
	Node *newNode = new Node(data);

	if(!head)
    {
		head = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;

	return;
}

template <typename T>
T LinkedList<T>::removeFromBack() 
{
	Node *curr = head;

	while(curr)
    {
		if(!curr->next)
        {
			T data (curr->data);
			delete curr;
			
            head = NULL;
			return data;
		}

		else
        {
			if(!curr->next->next)
            {
				T data (curr->next->data);
				curr->next = NULL;
                
				delete curr->next;
				return data;
			}
		}

		curr = curr->next;
	}

	return NULL;
}

template <typename T>
T LinkedList<T>::removeFromFront()
{
	if(!head)
    {
        return NULL;
    }

	Node *temp = head;
	T data (head->data);

	if(head->next)
    {
		head = head->next;
		delete temp;
		return data;
	}

	delete temp;
	head = NULL;

	return data;
}

template <typename T>
void LinkedList<T>::removeNode(Node *obj)
{
	if(obj == head)
	{
		Node *temp = head;
		head = head->next;
		
		delete temp;
		return;
	}

	Node *curr = head;

	while(curr)
	{
		if(curr->next == obj)
		{
			curr->next = obj->next;
			delete obj;
		}

		curr = curr->next;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::search(T data)
{
	if(!head)
    {
        return NULL;
    }

	Node* curr = head;

	while(curr)
    {
		if(curr->data == data)
        {
            return curr;
        }

		curr = curr->next;
	}

    // couldn't find node
	return NULL;
}

template <typename T>
void LinkedList<T>::display()
{
	if(!head)
    {
        return;
    }

	Node *curr = head;
	while(curr)
    {
		cout << curr->data << " " << endl;
		curr = curr->next;
	}

	cout << endl;
}