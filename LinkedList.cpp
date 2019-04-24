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
	Node(T d, Node<T> *n = 0) : data(d), next(n) {}
};

template <typename T>
Node<T> *head = NULL;

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
 * @brief Search for a Node by data
 *
 * @param data The data to search for, in the list of Nodes
 * @return boolean that determines if list has the respective data
 */

template <typename T>
bool LinkedList<T>::contains(T data)
{
    if (!head<T>)
    {
        return false;
    }

    Node<T> *curr = head<T>;
    while (curr->next != head<T>)
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

    Node<T> *curr = head<T>;

    while(curr->next)
    {
        ++counter;

        curr = curr->next;

        if (curr->next == head<T>)
        {
            ++counter;
            return counter;
        }

    }

//    if (curr->next == head<T>)
//    {
//        counter = 1;
//    }
//    else
//    {
//        while (curr->next != head<T>)
//        {
//            counter++;
//            curr = curr->next;
//        }
//    }

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
    Node<T> *temp;
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
    Node<T> *temp = new Node<T>(data); // create a temp Node

    if (head<T> == NULL)
    {
        // head is nonexistent, assign the first node to the new data
        temp->next = temp; // no head so make new node the head
        head<T> = temp; // set global head to newly created node

        return;
    }

    // head does exist, set new ptr
    Node<T> *tmp = head<T>;
    while(tmp->next != head<T>) // while the next ptr doesnt point to head (aka iterate to tail)
    {
        // keep iterating until we hit the node before the last node (the one that points to head)
        tmp = tmp->next;
    }

    tmp->next = temp; // from the second to last node, obtain last node and point to new node as new tail node
    temp->next = head<T>; // set the new node's next ptr to head since it is the tail node now

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
    Node<T> *tmp = head<T>; // obtain the head node
    Node<T> *prev = NULL;

    while(tmp->next != head<T>) // while the next ptr doesnt point to the head (aka iterate to tail)
    {
        if (tmp->data == data) // if we hit the requested data, break the loop
        {
            break;
        }

        prev = tmp;
        tmp = tmp->next; // iterate next node until we hit the data
    }

    if(tmp == head<T>) // if the data is found to be the head node
    {
        while(tmp->next != head<T>) 
        {
            tmp = tmp->next; // reassign the temporary node
        }

        tmp->next = head<T>->next; // since we are going to delete it, store the head's next node so we can reassign after destruction of the Node

        delete head<T>; // delete the head node which matches this data
        head<T> = tmp->next; // set the NEW head to the next element after the now-deleted node
    }
    else
    {
        prev->next = tmp->next; // store the Node's next ptr
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
    Node<T> *curr = head<T>;

    if (!head<T>)
	{
        // empty list
    }
    else if (getCurrentSize() == 1)
    {
        vec.push_back(curr->data);
    }
    else
    {
        while (curr->next != head<T>)
        {
            vec.push_back(curr->data);
            curr = curr->next;
        }
    }

    return vec;
}