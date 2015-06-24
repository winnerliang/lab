#include <iostream>

using namespace std;

int minnum(int a, int b, int c)
{
    int mins =a;
    if(mins > b)
        mins=b;
    if(mins >c)
        mins=c;
    return mins;
}

int searchingugly( int N)
{
    if(N<1)
        return -1;
    int *data = new int [N];
    data[0]=1;
    int index= 1;
    int * ugly2 = data, *ugly3 = data, *ugly5 =data;


    while(index<N)
    {
        int mins = minnum(*ugly2*2, *ugly3*3, *ugly5*5);
        data[index] = mins;
        while(mins >= *ugly2*2)
            ugly2++;
        while(mins >= *ugly3*3)
            ugly3++;
        while(mins >= *ugly5*5)
            ugly5++;
        index++;
    }
    int ugly = data[index-1];

    delete []data;
    cout<<ugly;
    return ugly;
}

int main()
{
    int N =7;

    searchingugly( N);

    return 0;
}
