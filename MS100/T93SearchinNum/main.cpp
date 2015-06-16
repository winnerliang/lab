#include <iostream>

using namespace std;

void  SearchingNums(int *pNums, int N)
{
    if(N<1)
        return;
    int * saving = new int [N];

    int leftmax = pNums[0];
    int cnt=0;
    saving[cnt++] = leftmax;

    for(int i=1; i<N; i++)
    {
        if(leftmax <= pNums[i])
        {
            saving[cnt++] = pNums[i];
            leftmax = pNums[i];
        }
        else
            while(saving[cnt-1]> pNums[i] && cnt>0) cnt--;
    }

    for(int i=0; i<cnt; i++)
        cout<<saving[i]<<"，";
    delete []saving;
}

int main()
{
    const int N =18;
    int pNums[N] = {1,3,2,4,6,7,8,5,10,9,13,25,212,21,234,232,213,242};
    SearchingNums(pNums, N);

    return 0;
}
