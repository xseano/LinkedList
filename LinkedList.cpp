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
 * @param h initial Node if provided
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
 * @brief Check if the list is empty (has no Nodes)
 *
 * @return boolean that determines if list has any Nodes
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
 * @return integer that represents amount of Nodes in list
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
    while (curr->next != head<T>)
	{
        counter++;
        curr = curr->next;
    }

    return counter;
}

/**
 * @brief Clear list of Nodes
 *
 * @note deletes each Node and frees respective memory
 */
template <typename T>
void LinkedList<T>::clear()
{
    Node<T>* temp;
    if (!head<T>)
    {
        return;
    }

    Node<T> *tmp = head<T>;

    while (tmp->next != head<T>)
	{
        Node<T> *temp = tmp;
        tmp = tmp->next;
        
        // destroy the head<T> of the list, incrementing until no Nodes left
        delete temp;
    }

    delete tmp;
    head<T> = NULL;
}

/**
 * @brief Add Node of data "T" to end of list
 *
 * @param data the data to add to the list
 */
template <class T>
void LinkedList<T>::addNode(T data)
{
    Node<T> *temp = new Node<T>(data);

    if (head<T> == NULL)
    {
        // head is nonexistent, assign the first node to the new data
        temp->next = temp;
        head<T> = temp;
        return; 
    }

    // head does exist, set new ptr
    Node<T> *tmp = head<T>;
    while(tmp->next != head<T>) // while the next ptr doesnt point to head (aka the tail)
    {
        tmp = tmp->next;
    }

    // set the head node to the new data created
    tmp->next = temp;
    temp->next = head<T>;

    return;
}

/**
 * @brief Remove Node of data "T" from end of list
 *
 * @param data the data to remove from the list
 */
template <class T>
void LinkedList<T>::removeNode(T data)
{
    Node<T> *tmp = head<T>;
    Node<T> *prev = NULL;

    while(tmp->next != head<T>)
    {
        if (tmp->data == data)
        {
            break;
        }

        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == head<T>)
    {
        while(tmp->next != head<T>)
        {
            tmp = tmp->next;
        }

        tmp->next = head<T>->next;

        delete head<T>;
        head<T> = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
        delete tmp;
    }

    return;
}

/**
 * @brief Converting list Node(s) to vector item(s)
 *
 * @return vector that represents a vector instance of all Node(s) in the list
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

    Node<T> *curr = head<T>;
    while (curr)
	{
        vec.push_back(curr->data);
        curr = curr->next;
    }

    return vec;
}