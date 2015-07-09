#include <iostream>

using namespace std;

void choosingsort(int pData[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(pData[i] > pData[j])
            {
                int t= pData[i];
                pData[i]=pData[j];
                pData[j]=t;
            }
        }
    }
}

int partsum(int pData[], int n)
{
    //sorting
    choosingsort(pData, n);

    int allsum = 0;
    for(int i=0; i<n; i++)
        allsum += pData[i];

    int Max = pData[n-1];
    cout<<"MAX  = "<<Max<<endl;

    int * pFlag = new int [n];

    for(int m=2; m<= allsum/Max; m++)
    {
        if( allsum % m == 0)
        {
            //fill the condition
            int segsum = allsum / m;
            int cursum =0;
            for(int i=0; i< n; i++)
            {
                if()
            }
        }
    }

    delete []pFlag;
}

int main()
{
    const in n=6;
    int pData[n] = {3,2,4,3,6};
    cout << partsum(pData, n) << endl;
    return 0;
}
