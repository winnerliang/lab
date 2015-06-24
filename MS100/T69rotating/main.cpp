#include <iostream>

using namespace std;

int rotating(int pdata[], int N)
{
    int start=0, ends= N-1, middle = 0;

    while(start < ends)
    {
        if(ends - start==1)
        {
            middle = ends;
            break;
        }
        middle = (start +ends)/2;
        if(pdata[start]<= pdata[middle])
            start = middle;
        else if(pdata[middle]<= pdata[ends] )
            ends = middle;
    }
    return pdata[middle];
}

int main()
{
    const int N = 5;
    int pdata [N]= {3,4,5,1,2};


    cout<<rotating(pdata, N);
    //cout << "Hello world!" << endl;
    return 0;
}
