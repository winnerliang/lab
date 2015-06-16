#include <iostream>
#include <list>

using namespace std;

void GetSum(int sum, int n)
{
    if(n<1 ||sum<1)
    {
        return ;
    }
    //int sum = m;
    static list<int> ilist;

    if(sum == n)
    {
        ilist.push_front(n);
        for(list<int>::iterator it = ilist.begin(); it!= ilist.end(); it++)
            cout<<" "<<(*it);
        cout<<endl;
        ilist.pop_front();
        GetSum(sum, n-1);
    }
    else if(sum >n)
    {
        ilist.push_front(n);
        GetSum(sum-n, n-1);
        ilist.pop_front();
        GetSum(sum, n-1);
    }
    else if(sum<n)
    {
        GetSum(sum, sum);
    }
}

int main()
{
    GetSum(20,10);
    return 0;
}
