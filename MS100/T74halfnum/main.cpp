#include <iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int partion(int pdata[], int start, int ends)
{
    int r = rand()%(ends-start+1);

    int t = pdata[r];
    pdata[r]= pdata[ends];
    pdata[ends] = t;

    int index=start-1;
    for(int i=start; i< ends; i++)
    {
        if(pdata[i] < pdata[ends])
        {
            index++;
            int t = pdata[index];
            pdata[index]= pdata[i];
            pdata[i] =t;
        }
    }
    index++;
    t = pdata[ends];
    pdata[ends]= pdata[index];
    pdata[index] =t;
    return index;
}

int halfnum(int pdata[], int N)
{
    srand(time(0));

    int start =0, ends = N-1;
    int index = partion(pdata, start, ends);
    while(index!= N/2)
    {
        if(index > N/2)
        {
            ends = index-1;
            index = partion(pdata, start, ends);
        }
        else
        {
            start = index+1;
            index = partion(pdata, start, ends);
        }
    }
    return pdata[index];
}

int shalf(int pdata[], int N)
{
    int num = pdata[0], cnt=1;

    for(int i=1; i<N; i++)
    {
        if(pdata[i] == num)
        {
            cnt++;
        }
        else
        {
            if(cnt==0)
            {
                num = pdata[i];
                cnt++;
            }
            else
                cnt--;
        }
    }
    if(cnt > 0)
        return num;
    else
        return 0;
}

int main()
{
    int N =10;
    int pdata[] = {1,2,2,1,1,1,3,1,5,1};

    cout<<shalf(pdata, N);
    return 0;
}
