#include <iostream>

using namespace std;

void MinHeapify(int *pData, int N, int index)
{
    int lchild = (index<<1)+1;
    int rchild = lchild+1;
    int t = index;
    if (index >= N)
        return;
    if (lchild<N && pData[lchild] < pData[t])
        t = lchild;
    if(rchild <N && pData[rchild] < pData[t])
        t = rchild;

    //swap maxvalue with index
    if(t!= index)
    {
        pData[t] ^= pData[index];
        pData[index] ^= pData[t];
        pData[t] ^= pData[index];
        MinHeapify(pData, N, t);
    }
}

int * GetLeastK(int *pData, int N, int k)
{
    for(int i=N<<1; i>-1; i--)
    {
        MinHeapify(pData, N, i);
    }

    for(int j=0; j <k;j++)
    {
        cout<<pData[0]<<" ";
        //swap pdata[0] and N-k;
        pData[0] ^= pData[N-j-1];
        pData[N-j-1] ^= pData[0];
        pData[0] ^= pData[N-j-1];
        MinHeapify(pData, N-j-1, 0);
    }

    return pData;
}

int main()
{
    int pData[]={1,2,3,4,5,6,1,7,2,3};
    GetLeastK(pData, 10, 3);
    return 0;
}
