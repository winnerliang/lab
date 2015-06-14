#include <iostream>

using namespace std;

void  Findcouple(int * pdata, int len, int sum, int * couple)
{
    int * sindex = pdata, *eindex = pdata+len-1;
    while(sindex < eindex)
    {
        int s = *sindex + *eindex;
        if(s < sum)
            sindex++;
        else if(s> sum)
            eindex--;
        else
            break;
    }
    if(sindex < eindex)
    {
        *couple++ = *sindex;
        *couple = *eindex;
    }
}

int main()
{
    int pdata[]={1,2,4,7,23};

    int * couple = new int [2];

    Findcouple(pdata, 5, 11, couple);
    cout<<*couple<<" "<<*(couple+1);

    delete []couple;

    return 0;
}
