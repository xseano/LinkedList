// Main .cpp
// oberoi, sean
// ssoberoi

#include "LinkedList.h"

int main()
{
    LinkedList* llist = new LinkedList(0, NULL);

    // 100 nodes created
    for (int i = 0; i < LIST_LEN; i++)
    {
        srand(time(0));
        
        int ran = (rand() % LIST_LEN);
        llist->append(ran++);
    }

    llist->display();

    int list_length = llist->getLength();
    Node finalNode = *(llist->getNext());
    
    cout << "List Length: " << list_length << endl;
    cout << "Final Obj: " << finalNode.data << endl;
    
    delete llist;
    
    return 0;
}