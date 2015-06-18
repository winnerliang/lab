#include <iostream>
#include "mylist.h"

using namespace std;

void listsort(MyList * header)
{
    MyList * prev = header, * curt = header->next;
    MyList * head = header;

    for( ; curt!=NULL ; )
    {
        MyList *pcnt = head ;
        for(; pcnt != curt; pcnt = pcnt->next)
        {
            if(head->value > curt->value)
            {
                head = curt;
                prev->next = curt->next;
                curt->next = pcnt;
                curt = prev -> next;
                break;
            }
            if(pcnt->next->value > curt->value)
            {
                //swap node
                prev->next = curt->next;
                curt->next = pcnt->next;
                pcnt->next = curt;
                curt = prev->next;
                break;
            }
        }
        if(pcnt == curt)
        {
            prev = prev->next;
            curt =curt->next;
        }
    }

}

int main()
{
    MyList * header = createlist(10);

    displist(header);
    cout<<endl;

    listsort(header);

    displist(header);
    cout<<endl;

    return 0;
}
