#include <iostream>

using namespace std;

bool IsBSTpostorder(int * pdata, int len)
{
    if(pdata ==NULL || len<=0)
        return false;

    int maxleft =0;
    int root = pdata[len-1];

    for(; maxleft< len-1; maxleft++)
    {
        if(pdata[maxleft]> root)
            break;
    }
    int minright = maxleft;

    for(int i= minright ; i<len-1; i++)
    {
        if(pdata[i]< root)
            return false;
    }

    bool left = true, right = true;

    if (maxleft>0)
        left = IsBSTpostorder(pdata, maxleft);
    if(minright <len-1)
    {
        right = IsBSTpostorder(pdata+maxleft, len -1 - minright);
    }
    return left && right;
}

int main()
{
    //int pdata[]={5,7,6,9,11,10,8};
    int pdata[]={7,4,6,5};
    cout<< IsBSTpostorder(pdata, 4);
    return 0;
}
