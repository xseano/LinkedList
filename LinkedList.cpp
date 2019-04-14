// LinkedList.cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(Node* h)
    : head(h)
{
    //
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if (!head)
	{
        return true;
    }

    return false;
}

template <typename T>
int LinkedList<T>::getCurrentSize()
{
    int counter = 0;

    if (!head)
	{
        return 0;
    }

    Node* curr = head;
    while (curr)
	{
        counter++;
        curr = curr->next;
    }

    return counter;
}

template <typename T>
void LinkedList<T>::clear()
{
    Node* temp;
    while (head)
	{
        temp = head;
        head = head->next;
        // destroy the head of the list, incrementing until no nodes left
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::add(T data)
{
    Node* newNode = new Node(data);

    if (!head)
	{
        // no nodes in list, create head
        head = newNode;
        return;
    }

    Node* curr = head;

    while (curr)
	{
        if (!curr->next)
		{
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    }
}

template <typename T>
void LinkedList<T>::prepend(T data)
{
    Node* newNode = new Node(data);

    if (!head)
	{
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;

    return;
}

template <typename T>
void LinkedList<T>::pop()
{
    Node* curr = head;

    while (curr)
	{
        if (!curr->next)
		{
            delete curr;

            head = NULL;
            return;
        }

        else
		{
            if (!curr->next->next)
			{
                curr->next = NULL;

                delete curr->next;
                return;
            }
        }

        curr = curr->next;
    }

    return;
}

template <typename T>
void LinkedList<T>::shift()
{
    if (!head)
	{
        return;
    }

    Node* temp = head;

    if (head->next)
	{
        head = head->next;
        delete temp;
        return;
    }

    delete temp;
    head = NULL;

    return;
}

template <typename T>
bool LinkedList<T>::contains(T data)
{
    if (!head)
	{
        return false;
    }

    Node* curr = head;
    while (curr)
	{
        if (curr->data == data)
		{
            return true;
        }

        curr = curr->next;
    }

    // couldn't find node
    return false;
}

template <typename T>
int LinkedList<T>::getFrequencyOf(T data)
{
    int counter = 0;

    if (!head)
	{
        return 0;
    }

    if (contains(data) == false)
	{
        return 0;
    }

    Node* curr = head;
    while (curr)
	{
        if (curr->data == data)
		{
            // data found, increment counter
            counter++;
        }

        curr = curr->next;
    }

    return counter;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector()
{
    std::vector<T> vec;

    if (!head)
	{
        vec.push_back(0);
        return vec;
    }

    Node* curr = head;

    while (curr)
	{
        vec.push_back(curr->data);
        curr = curr->next;
    }

    return vec;
}

template <typename T>
void LinkedList<T>::displayList()
{
    if (!head)
	{
        return;
    }

    Node* curr = head;

    cout << "\n--------\n";

    while (curr)
	{
        cout << curr->data << endl;

        curr = curr->next;
    }

    cout << "List size: " << getCurrentSize() << endl;
    cout << "--------" << endl;
}