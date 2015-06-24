#include <iostream>

using namespace std;

typedef struct ComplexNode
{
    int m_nValue;
    ComplexNode* m_pNext;
    ComplexNode* m_pSibling;
}ComplexNode;

ComplexNode* Clone(ComplexNode* pHead)
{
    ComplexNode * pcnt = pHead, * newHead = NULL;
    if(pHead ==NULL)
        return NULL;

    //create nodes
    for( ; pcnt!= NULL; pcnt = pcnt->m_pNext->m_pNext)
    {
        ComplexNode * newnode = new ComplexNode[1];
        newnode->m_nValue = pcnt->m_nValue;
        newnode->m_pNext = pcnt->m_pNext;
        pcnt->m_pNext = newnode;
    }

    //copy the m_pSibling
    for(pcnt = pHead; pcnt!= NULL; pcnt = pcnt->m_pNext->m_pNext)
    {
        pcnt->m_pNext->m_pSibling = (pcnt->m_pSibling != NULL )?pcnt->m_pSibling->m_pNext:NULL;
    }

    //separting
    newHead = pHead->m_pNext;
    ComplexNode * pcnto = pHead, * pcntn = newHead;
    for(; pcnto!= NULL; pcnto = pcnto->m_pNext, pcntn = pcntn->m_pNext)
    {
        pcnto->m_pNext = pcntn->m_pNext;
        pcntn->m_pNext = (pcntn->m_pNext!= NULL)?pcntn->m_pNext->m_pNext:NULL;
    }
    return newHead;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
