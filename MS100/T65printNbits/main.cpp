#include <iostream>

using namespace std;

void printNbits(const int Nbits, int curtbit, int *data)
{
    if(curtbit==Nbits-1)
    {
        //display the num
        int i=0;
        for( ; i< Nbits; i++)
            if(data[i]!= 0)
                break;
        while(i<Nbits)
        {
            cout<<data[i];
            i++;
        }
        cout << endl;
        return ;
    }
    for(data[curtbit+1]=0;data[curtbit+1]<10; data[curtbit+1]++ )
        printNbits(Nbits, curtbit+1, data);
}

int main()
{
    const int N=4;
    int data[N];
    for(int i=0; i<N; i++)
        data[i]=0;
    for(int i=0; i<10; i++)
    {
        data[0]=i;
        printNbits(N, 0, data);
    }

    return 0;
}
