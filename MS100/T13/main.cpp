#include <iostream>
#include "mylist.h"

using namespace std;

MyList * GetBackwardK(MyList * plist, int n)
{
    MyList * fast= plist, * slow = plist;

    while(n>0)
    {
        fast = fast->next;
        n--;
    }
    while(fast!= NULL)
    {
        fast = fast->next;
        slow =slow->next;
    }
    return slow;
}

int main()
{
    MyList * test = createlist(10);
    displist(test);

    cout<< GetBackwardK(test, 8)->value;
    return 0;
}
