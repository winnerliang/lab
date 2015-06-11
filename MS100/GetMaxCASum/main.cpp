#include <iostream>

using namespace std;

int main()
{
    int pData[] = {1,-2,3,10,-4,7,2,-5};

    int MaxValue = 0;
    int Prev =0, Curt =0;
    for (int i =0; i<8; i++)
    {
        if (i==0)
        {
            Curt = pData[0];
            Prev = Curt;
            MaxValue = Curt;
        }
        else
        {
            if (Prev >0)
            {
                Curt = Prev + pData[i];
            }
            else
            {
                Curt = pData[i];
            }
            if (MaxValue < Curt)
                MaxValue = Curt;
            Prev = Curt;
        }
    }

    cout<< MaxValue;
    return 0;
}
