#include <iostream>
#include "mylist.h"

using namespace std;

void printlist(MyList * mylist)
{
    if(mylist ==NULL)
        return ;
    printlist(mylist->next);
    cout<< mylist->value<<", ";
}

int main()
{
    MyList * mylist = createlist(10);

    printlist(mylist);
    return 0;
}
