// Main .cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

typedef float dataType;

/**
 * @brief Display Nodes in the list
 */
void displayList(std::vector<dataType> list)
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
    LinkedList<dataType>* LL = new LinkedList<dataType>();

    if ((LL->isEmpty()))
	{
        cout << "\n--------\nNew List";
    }

    LL->addNode(1.87);
    LL->addNode(2.52);
    LL->addNode(2.94);
    LL->addNode(3.17);
    LL->addNode(3.64);

    displayList(LL->toVector());

    cout << "Now let's reverse the list...";
    displayList(LL->reverseVector());

    if (!(LL->contains(4.39)))
    {
        cout << "4.39 doesn't exist, let's add it!";
        LL->addNode(4.39);
        displayList(LL->toVector());
    }

    cout << "Lets remove 2.94 and 3.17!";
    LL->removeNode(2.94);
    LL->removeNode(3.17);
    displayList(LL->toVector());

    cout << "Let's reverse the list again!";
    displayList(LL->reverseVector());

    cout << "Lets add another 1.87...";
    dataType demoVal = 1.87;

    LL->addNode(demoVal);
    displayList(LL->toVector());

    cout << "Wait.. how many times is " << demoVal << " in the list though?" << endl;
    cout << "Looks like " << demoVal << " has " << LL->getFrequencyOf(demoVal) << " occurrences in the list!" << endl;

    return 0;
}