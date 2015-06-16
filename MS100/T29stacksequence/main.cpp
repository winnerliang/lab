#include <iostream>
#include<stack>

using namespace std;

bool Isstacksequence(int *push, int *pop, int n)
{
    stack<int> ss;

    bool bret = false;
    int *cntp = push, *cnti = pop;
    if(push!= NULL && pop!= NULL && n>0)
    {
        while(pop- cnti <n)
        {
            while(ss.empty()||ss.top()!= *pop)
            {
                if(push - cntp == n)
                    break;
                ss.push(*push);
                push++;
            }
            if(*pop!= ss.top())
                break;
            ss.pop();
            pop ++;

        }
        if(pop - cnti == n && ss.empty())
            bret = true;
    }

    return bret ;
}

int main()
{
    int push[]={1,2,3,4,5};
    int pop[]={4,3,5,1,2};
    cout << Isstacksequence(push, pop, 5) << endl;
    return 0;
}
