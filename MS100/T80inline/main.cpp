#include <iostream>

using namespace std;

int bit_cnt(int n)
{
    int cnt=0;
    for(; n; n&=n-1, ++cnt);
    return cnt;
}

int Inaline(void)
{
    int availcnt =0;
    int F[6], S[6];

    for(int sce =1; sce< 1<<12; sce++)
    {
        if(bit_cnt(sce)==6)
        {
            //firstly statisfy the condition
            int fcnt=0, scnt=0;
            for(int i=1; i<13 ; i++)
            {
                if(sce & (1<<(i-1)))
                {
                    F[fcnt++] = i;
                }
                else
                    S[scnt++]= i;
            }
            int iss =1;
            for(int i=0; i<6; i++)
            {
                if(F[i]>S[i])
                {
                    iss=0;
                    break;
                }
            }
            availcnt += iss;

        }
    }

    return availcnt;
}

int main()
{
    cout << Inaline()<< endl;
    return 0;
}
