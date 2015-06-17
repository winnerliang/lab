#include <iostream>

using namespace std;

int choosing(int * pdata, int N)
{
    if(N<1)
        return 0;

    int cnt =1, index=0;
    for(; cnt < N ; cnt++)
    {
        if(index < 0 || pdata[cnt] >= pdata[index])
        {
            index++;
            pdata[index] = pdata[cnt];
        }
        else
        {
            while(index >=0 && pdata[cnt]< pdata[index])index--;

        }

    }
    return index +1;
}

int main()
{
    const int N=13;
    int pdata[N] = {3,4,2,5,7,6,10,11,13,23,2,24,25};

    int len = choosing(pdata, N);
    cout<< len <<endl;
    for(int i=0; i<len; i++)
        cout<< pdata[i]<<" ,";

    return 0;
}
