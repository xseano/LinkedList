// LinkedList.cpp
// oberoi, sean
// ssoberoi

template <typename T>
struct Node
{
	// Data and next position
	T data;
	Node* next;

	// initialization list
	Node() {}
	Node(T d, Node<T>* n = 0) : data(d), next(n) {}
};

template <typename T>
Node<T>* head = NULL;

/**
 * @brief List Constructor
 *
 * @param h initial Node<T> if provided
 */
template <typename T>
LinkedList<T>::LinkedList()
{
    head<T> = NULL;
}

/**
 * @brief List Destructor
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

/**
 * @brief Check if the list is empty (has no Node<T>s)
 *
 * @return boolean that determines if list has any Node<T>s
 */
template <typename T>
bool LinkedList<T>::isEmpty()
{
    if (!head<T>)
	{
        return true;
    }

    return false;
}

/**
 * @brief Obtain size of the list
 *
 * @return integer that represents amount of Node<T>s in list
 */
template <typename T>
int LinkedList<T>::getCurrentSize()
{
    int counter = 0;

    if (!head<T>)
	{
        return 0;
    }

    Node<T>* curr = head<T>;
    while (curr)
	{
        counter++;
        curr = curr->next;
    }

    return counter;
}

/**
 * @brief Clear list of Node<T>s
 *
 * @note deletes each Node<T> and frees respective memory
 */
template <typename T>
void LinkedList<T>::clear()
{
    Node<T>* temp;
    while (head<T>)
	{
        temp = head<T>;
        head<T> = head<T>->next;
        // destroy the head<T> of the list, incrementing until no Node<T>s left
        delete temp;
    }
}

/**
 * @brief Add Node<T> to the end of the list
 *
 * @param data the data to create the Node<T>
 */
template <typename T>
void LinkedList<T>::add(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (!head<T>)
	{
        // no Node<T>s in list, create head<T>
        head<T> = newNode;
        return;
    }

    Node<T>* curr = head<T>;

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

/**
 * @brief Add Node<T> to start of the list
 *
 * @param data the data to create the Node<T>
 */
template <typename T>
void LinkedList<T>::prepend(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (!head<T>)
	{
        head<T> = newNode;
        return;
    }

    newNode->next = head<T>;
    head<T> = newNode;

    return;
}

/**
 * @brief Remove Node<T> from end of list
 *
 */
template <typename T>
void LinkedList<T>::pop()
{
    Node<T>* curr = head<T>;

    while (curr)
	{
        if (!curr->next)
		{
            delete curr;

            head<T> = NULL;
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

/**
 * @brief Remove Node<T> from start of list
 */
template <typename T>
void LinkedList<T>::shift()
{
    if (!head<T>)
	{
        return;
    }

    Node<T>* temp = head<T>;

    if (head<T>->next)
	{
        head<T> = head<T>->next;
        delete temp;
        return;
    }

    delete temp;
    head<T> = NULL;

    return;
}

/**
 * @brief Search for a Node<T> by data
 *
 * @param data The data to search for, in the list of Node<T>s
 * @return boolean that determines if list has the respective data
 */

template <typename T>
bool LinkedList<T>::contains(T data)
{
    if (!head<T>)
	{
        return false;
    }

    Node<T>* curr = head<T>;
    while (curr)
	{
        if (curr->data == data)
		{
            return true;
        }

        curr = curr->next;
    }

    // couldn't find Node<T>
    return false;
}

/**
 * @brief Occurence(s) of data in the list
 *
 * @param h initial Node<T> if provided
 * @return int that describes how many times the data exists in the list
 */
template <typename T>
int LinkedList<T>::getFrequencyOf(T data)
{
    int counter = 0;

    if (!head<T>)
	{
        return 0;
    }

    if (contains(data) == false)
	{
        return 0;
    }

    Node<T>* curr = head<T>;
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

/**
 * @brief Converting list Node<T>(s) to vector item(s)
 *
 * @return vector that represents a vector instance of all Node<T>s in the list
 */
template <typename T>
std::vector<T> LinkedList<T>::toVector()
{
    std::vector<T> vec;

    if (!head<T>)
	{
        vec.push_back(0);
        return vec;
    }

    Node<T>* curr = head<T>;

    while (curr)
	{
        vec.push_back(curr->data);
        curr = curr->next;
    }

    return vec;
}

/**
 * @brief Display Node<T>s in the list
 */
template <typename T>
void LinkedList<T>::displayList()
{
    if (!head<T>)
	{
        return;
    }

    Node<T>* curr = head<T>;

    cout << "\n--------\n";

    while (curr)
	{
        cout << curr->data << endl;

        curr = curr->next;
    }

    cout << "List size: " << getCurrentSize() << endl;
    cout << "--------" << endl;
}