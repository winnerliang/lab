#include <iostream>

using namespace std;

int main()
{
    int pdata[1001];
    for(int i=0; i<1000; i++)
        pdata[i]=1+i;
    pdata[1000] = 100;

    int saved[1000];
    for(int i=0; i<1000; i++)
        saved[i] =0;
    for(int i=0; i<1001; i++)
    {
        if(saved[pdata[i]-1] != 0)
        {
            cout<< pdata[i]<<" ";
        }
        else
        {
            saved[pdata[i]-1] = 1;
        }
    }

    int sum1 = 0, sum2;
    for (int i=0; i<1000; i++)
    {
        sum1 += pdata[i];
        sum2 += i+1;
    }

    sum1+= pdata[1000];
    cout<<sum1-sum2;
    return 0;
}
