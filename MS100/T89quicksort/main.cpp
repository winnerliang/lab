#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int partsort(int pdata[], int start, int ends)
{
    if(start>=ends)
        return -1;
    int r = rand()%(ends-start +1)  + start;

    int t = pdata[ends];
    pdata[ends]= pdata[r];
    pdata[r] = t;

    int index = start-1;
    for(int cnt=start; cnt<ends; cnt++)
    {
        if(pdata[cnt] <= pdata[ends])
        {
            index++;
            int t = pdata[index];
            pdata[index]=  pdata[cnt];
            pdata[cnt] = t;
        }
    }
    index++;
    t = pdata[index];
    pdata[index] = pdata[ends];
    pdata[ends] = t;

    return index;
}

void quicksort(int pdata[], int start, int ends)
{
    int r = partsort(pdata, start, ends);
    if(r!= -1)
    {
        if(r>start)
            quicksort(pdata, start ,r-1);
        if(r<ends)
            quicksort(pdata, r+1, ends);
    }
}

int main()
{
    const int N= 17;
    int p[N]={1,4,2,6,5,3,0,9,7,8,20,5,24,4,3,2,10};

    srand(time(0));

    quicksort(p, 0, N-1);

    for(int i=0; i<N; i++)
        cout<<p[i]<<", ";

    return 0;
}
