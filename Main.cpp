// Main .cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

/**
 * @brief Display Nodes in the list
 */
void displayList(std::vector<int> list)
{
    cout << "\n--------\n";

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }

    cout << "List size: " << list.size() << endl;
    cout << "--------" << endl;
}

int main()
{
    LinkedList<int>* LL = new LinkedList<int>();

    if ((LL->isEmpty()) == true)
	{
        cout << "\n--------\nNew List\n";
    }

    LL->addNode(10);
    LL->addNode(20);
    LL->addNode(30);
    LL->addNode(40);
    LL->addNode(50);
    LL->addNode(60);

    displayList(LL->toVector());

    if (!(LL->contains(60)))
    {
        cout << "60 doesn't exist, let's add it!";
        LL->addNode(60);
    }

    displayList(LL->toVector());

    LL->removeNode(30);
    LL->removeNode(40);

    displayList(LL->toVector());

    return 0;
}