#include <iostream>

using namespace std;

int findfirstbit(int n)
{
    return n&~(n-1);
}

void findtwo(int * data, int N , int & a , int & b)
{
    int allsum=0;
    for(int i = 0; i < N; i++)
        allsum ^= data[i];

    //searching for the first bit 1
    int sum = findfirstbit(allsum);

    a = 0, b = 0;
    for(int i=0; i < N; i++)
    {
        if((data[i] & sum )== sum)
        {
            a ^= data[i];
        }
        else
        {
            b ^= data[i];
        }
    }
    cout<< a <<" ," << b << endl;
}

void findthree(int *data, int N, int & a, int & b, int & c)
{
    int allsum =0;
    for(int i=0; i<N; i++)
        allsum ^= data[i];

    int flagallsum=0;
    for(int i=0; i<N; i++)
    {
        flagallsum ^= findfirstbit(allsum^data[i]);
    }
    flagallsum = findfirstbit(flagallsum);

    a = 0;
    for(int i=0; i<N; i++)
        if(findfirstbit(allsum^data[i])== flagallsum)
        {
            a^= data[i];
        }
    for(int i=0; i<N; i++)
    {
        if(data[i]== a)
        {
            data[i]= data[N-1];
            data[N-1]=a;
            break;
        }
    }
    cout<<a<<" ,";
    findtwo(data, N-1, b,c);

    return ;
}

int main()
{
    const int N=9;
    int data[N]={1,1,1,1,7,2,3,4,4};
    int a,b,c ;
    findthree(data, N,a,b,c);

    return 0;
}
