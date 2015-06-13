#include <iostream>
#include "mylist.h"

using namespace std;

MyList * revesinglist(MyList * root)
{
    if(root==NULL)
        return NULL;
    MyList * pCurt = root, * pPrev = NULL;
    while(pCurt!= NULL)
    {
        MyList * pNext = pCurt->next;
        pCurt->next = pPrev;
        pPrev = pCurt;
        pCurt = pNext;
    }
    return pPrev;
}

MyList * RevesingList(MyList * root, MyList *& endnode)
{
    if(root== NULL || root->next ==NULL)
    {
        endnode = root;
        return root;
    }

    MyList * pNext = RevesingList(root->next ,  endnode);
    pNext->next = root;
    root->next = NULL;
    return root;

}

int main()
{
    MyList * root = createlist(10);
    displist(root);

    root = revesinglist(root);

    //displist(root);
    displist(root);
    return 0;
}
