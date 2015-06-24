#include<stdio.h>

using namespace std;

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * pcnt = head, * newHead = NULL;
        if(head ==NULL)
            return NULL;

        //create nodes
        for( ; pcnt!= NULL; pcnt = pcnt->next->next)
        {
            RandomListNode * newnode = new RandomListNode(pcnt->label);
            newnode->next = pcnt->next;
            pcnt->next = newnode;
        }

        //copy the m_pSibling
        for(pcnt = head; pcnt!= NULL; pcnt = pcnt->next->next)
        {
            pcnt->next->random = (pcnt->random != NULL )?pcnt->random->next:NULL;
        }

        //separting
        newHead = head->next;
        RandomListNode * pcnto = head, * pcntn = newHead;
        for(; pcnto!= NULL; pcnto = pcnto->next, pcntn = pcntn->next)
        {
            pcnto->next = pcntn->next;
            pcntn->next = (pcntn->next!= NULL)?pcntn->next->next:NULL;
        }
        return newHead;
    }
};
