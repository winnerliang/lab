#include <iostream>

using namespace std;

void sortodd(int *pdata, int N)
{
    int *start= pdata , * ends = pdata + N-1;

    while(start < ends)
    {
        while( (start < pdata +N-1 )&& (*start%2==1)) start++;
        while((ends >= 0 )&& (*ends%2==0))ends--;
        if(start<ends)
        {
            int t = *start;
            *start = *ends;
            *ends =t;
        }
    }
}

int main()
{
    const int N =5;
    int pdata[N]={1,4,3,2,4};

    sortodd(pdata, N);

    for(int i=0; i<N; i++)
        cout<<pdata[i]<<" ,";

    return 0;
}
