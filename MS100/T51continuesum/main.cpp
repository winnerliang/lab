#include <iostream>

using namespace std;

void continuesum(int sum)
{
    int n = 2, na1 = 0;
    while( n*(n+1) <= 2*sum)
    {
        na1 = sum - ((n-1)*n/2);
        if(na1/ n > 0 && na1 % n==0 )
        {
            int t = na1/n;
            cout << t << "-" << t+n-1 << endl;
        }
        n++;
    }
}

void continuesumother(int sum)
{
    int start=1, ends=2, mid = sum/2, cursum = 3;
    while(start <= mid && ends < sum)
    {
        if(cursum == sum)
        {
            cout<<start<<"-"<<ends<<endl;
        }
        while(cursum> sum && start < mid)
        {
            cursum-=start;
            start++;
            if(cursum == sum)
            {
                cout<<start<<"-"<<ends<<endl;
            }
        }
        ends++;
        cursum+=ends;
    }
    return ;
}

int main()
{
    continuesumother(3);
    return 0;
}
