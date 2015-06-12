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
        t->value=3;
        t->next = NULL;
        pCurt1->next = t;
        pCurt1 = pCurt1->next;
        pCurt2->next = t;
        pCurt2 = pCurt2->next;
    }
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

int main()
{
    //create h1 ,h2
    myList * h1 = new myList[1];
    h1->value =1;
    h1->next = NULL;
    myList * h2 = new myList[1];
    h2->next = NULL;
    h2->value=2;

    creatList(h1, h2);
    dispList(h1, h2);

    myList * pCurt1 = h1, *pCurt2 = h2;

    while(pCurt1->next!= NULL && pCurt2->next!=NULL)
    {
        pCurt1 = pCurt1->next;
        pCurt2 = pCurt2->next;
    }

    if(pCurt1->next==NULL)
    {
        pCurt1 = h2;
        while(pCurt2->next!=NULL)
        {
            pCurt1=pCurt1->next;
            pCurt2=pCurt2->next;
        }
        pCurt2 = h1;
    }
    else
    {
        pCurt2 = h1;
        while(pCurt1->next!=NULL)
        {
            pCurt1=pCurt1->next;
            pCurt2=pCurt2->next;
        }
        pCurt1 = h2;
    }

    while(pCurt1!= NULL && pCurt2!= NULL)
    {
        pCurt1=pCurt1->next;
        pCurt2=pCurt2->next;
        if(pCurt1 == pCurt2 && pCurt1!= NULL)
        {
            cout<<"xiangjiao";
            return 0;
        }
    }

    cout<<"buxiangjiao!";
    return 0;
}
