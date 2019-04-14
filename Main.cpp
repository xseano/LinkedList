// Main .cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

int main()
{
	LinkedList<int> *LL = new LinkedList<int>();

	if ((LL->isEmpty()) == true)
	{
		cout << "\n--------\nNew List\n";
	}

	LL->add(10);
	LL->add(20);
	LL->add(30);
	LL->add(40);
	LL->add(50);
	LL->display();

	cout << "Adding 60 to the front of the list!";

	LL->prepend(60);
	LL->display();

	cout << "Removing the last node...";

	LL->pop();
	LL->display();

	cout << "Removing the first node...";
	LL->shift();
	LL->display();

	cout << "Does 60 still exist in the list?" << endl;

	if((LL->contains(60)) == false)
	{
		cout << "60 doesn't exist, let's add it again!";
		LL->add(60);
		LL->display();
	}

	cout << "Lets add 40 to the front of the list...";
	LL->prepend(40);
	LL->display();

	cout << "Wait.. how many times is 40 in the list though?" << endl;
	cout << "Looks like 40 has " <<  LL->getFrequencyOf(40) << " occurences in the list!" << endl;

	return 0;
}