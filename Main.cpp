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

    if ((LL->isEmpty()))
	{
        cout << "\n--------\nNew List\n";
    }

    LL->addNode(10);
    LL->addNode(20);
    LL->addNode(30);
    LL->addNode(40);
    LL->addNode(50);

    displayList(LL->toVector());

    cout << "Now let's reverse the list..." << endl;
    displayList(LL->reverseVector());

    if (!(LL->contains(60)))
    {
        cout << "60 doesn't exist, let's add it!";
        LL->addNode(60);
        displayList(LL->toVector());
    }

    cout << "Lets remove 30 and 40!";
    LL->removeNode(30);
    LL->removeNode(40);
    displayList(LL->toVector());

    cout << "Let's reverse the list again!" << endl;
    displayList(LL->reverseVector());

    cout << "Lets add another 20...";
    LL->addNode(20);
    displayList(LL->toVector());

    int demoVal = 20;
    cout << "Wait.. how many times is " << demoVal << " in the list though?" << endl;
    cout << "Looks like " << demoVal << " has " << LL->getFrequencyOf(demoVal) << " occurrences in the list!" << endl;

    return 0;
}