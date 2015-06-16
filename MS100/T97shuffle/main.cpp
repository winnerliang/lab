#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void swap(int *a, int *b)
{

    int t = *a;
    *a = *b;
    *b =t;

}

void shuffle(int *pCards, int n)
{
    srand(time(0));
    for(int i=0; i<n; i++)
        pCards[i] = i+1;

    for(int i = 0; i < n-1; i++)
    {
        int r = rand()%(n-i);
        if(pCards[r] ==0 || pCards[n-1-i] ==0)
            cout<<"error";
        /*
        *(pCards+r) ^= *(pCards+n-1-i);
        *(pCards+n-1-i) ^= *(pCards+r);
        *(pCards+r) ^= *(pCards+n-1-i);*/

        swap(pCards+r, pCards+n-1-i);
        if(pCards[r] ==0 || pCards[n-1-i] ==0)
            cout<<"error";
    }

    for(int i=0; i<n; i++)
        cout<<pCards[i]<<" ";

}

int main()
{
    int n = 54;
    int *pCards = new int [n];

    shuffle(pCards, n);

    delete [] pCards;
    return 0;
}
