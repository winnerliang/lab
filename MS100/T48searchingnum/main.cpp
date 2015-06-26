#include <iostream>

using namespace std;

int searchingnum(int pData[], int N, int src)
{
    int start=0, end = N-1, mid = N/2;

    while(start < end)
    {
        mid = (start + end )/2;
        if( pData[mid] == src)
            return mid;
        else if( pData[start]== src)
            return start;
        else if(pData[end] == src)
            return end;
        if( (src < pData[start] && pData[start] < pData[mid] ) || (pData[start] < pData[mid] && pData[mid] < src) || (pData[mid]< src && src < pData[start]))
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int main()
{
    const int N =20;
    int pData[N] ={3,2,1,20,19,18,17,16,15,14,13,12,11,10,9,8,7, 6,5,4 };

    for(int i=0; i<N; i++)
        cout<<pData[i]<<":"<<searchingnum(pData, N , pData[i])<<endl;
    return 0;
}
