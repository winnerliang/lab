#include <iostream>

using namespace std;


struct myList
{
    int value;
    myList * next;
};

void creatList(myList *h1, myList *h2)
{
    myList * pCurt1 = h1, *pCurt2 = h2;
    for(int i=0; i<3; i++)
    {
        myList * t = new myList[1];
        t->value=1;
        t->next = NULL;
        pCurt1->next = t;
        pCurt1 = pCurt1->next;
    }
    myList * pNode1 = pCurt1;

    for(int i=0; i<5; i++)
    {
        myList * t = new myList[1];
        t->value=2;
        t->next = NULL;
        pCurt2->next = t;
        pCurt2 = pCurt2->next;
    }

    for(int i=0; i<7; i++)
    {
        myList * t = new myList[1];
        t->value=i;
        t->next = NULL;
        pCurt1->next = t;
        pCurt1 = pCurt1->next;
        pCurt2->next = t;
        pCurt2 = pCurt2->next;
    }

    pCurt1-> next = pNode1->next;
}

void dispList(myList *h1, myList*h2)
{
    myList * pCurt1 = h1, *pCurt2 = h2;
    while(pCurt1->next!= NULL)
    {
        cout<<pCurt1->value<<" ";
        pCurt1 = pCurt1->next;
    }
    cout<<endl;
    while(pCurt2->next!= NULL)
    {
        cout<<pCurt2->value<<" ";
        pCurt2 = pCurt2->next;
    }
}

//is loop and return the first loop node
myList * Isloop(myList * h)
{
    if(h==NULL)
        return NULL;
    myList *fast = h, *slow = h;

    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            //across point
            myList * pCurt = h;
            while(slow != pCurt)
            {
                slow = slow->next;
                pCurt= pCurt->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main()
{
    myList *h1 = new myList[1], *h2 = new myList[1];
    creatList(h1,h2);

    myList * node1 = Isloop(h1);

    myList * node2 = Isloop(h2);

    if(node1 == node2 )
    {
        cout<<"xiangjiao";
    }
    else
        cout<<"buxiangjiao";
/*
    for(int i=0; i<10; i++)
    {
        cout<<node1->value<<" ";
        node1 = node1->next;
    }
    cout<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<node2->value<<" ";
        node2 = node2->next;
    }
    */

    return 0;
}
