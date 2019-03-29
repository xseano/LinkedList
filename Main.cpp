// Main .cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

int main()
{
	LinkedList<int> *LL = new LinkedList<int>(NULL);

	cout << "Adding 50, 70 20, and 10 to the tail of the list..." << endl;
	LL->addToBack(50);
	LL->addToBack(70);
	LL->addToBack(20);
	LL->addToBack(10);
	LL->display();

	cout << "Adding 10 to the front..." << endl;
	LL->addToFront(10);
	LL->display();

	//cout << "Removing value 70 from the list..." << endl;
	//LL->removeNode(LL->search(30));
	//LL->display();

	cout << "Adding 30 before item 10..." << endl;
	LL->addToFront(30);
	LL->display();

	cout << "Removing node from back of list..." << endl;
	cout << LL->removeFromBack() << " removed from tail." << endl;
	LL->display();

	cout << "Removed a node from the head of the list..." << endl;
	cout << LL->removeFromFront() << endl;
	LL->display();

	return 0;
}