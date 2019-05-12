// Main .cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

typedef std::string dataType;

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
        cout << "\n--------\nNew List\n";
    }

    LL->addNode("one");
    LL->addNode("two");
    LL->addNode("three");
    LL->addNode("four");
    LL->addNode("five");

    displayList(LL->toVector());

    cout << "Now let's reverse the list..." << endl;
    displayList(LL->reverseVector());

    if (!(LL->contains("six")))
    {
        cout << "6 doesn't exist, let's add it!";
        LL->addNode("six");
        displayList(LL->toVector());
    }

    cout << "Lets remove 3 and 4!";
    LL->removeNode("three");
    LL->removeNode("four");
    displayList(LL->toVector());

    cout << "Let's reverse the list again!" << endl;
    displayList(LL->reverseVector());

    cout << "Lets add another 2...";
    dataType demoVal = "two";

    LL->addNode(demoVal);
    displayList(LL->toVector());

    cout << "Wait.. how many times is " << demoVal << " in the list though?" << endl;
    cout << "Looks like " << demoVal << " has " << LL->getFrequencyOf(demoVal) << " occurrences in the list!" << endl;

    return 0;
}