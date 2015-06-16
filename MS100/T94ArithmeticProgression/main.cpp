#include <iostream>

using namespace std;

void ArithmeticProgression(int pdata[], int N)
{
    if(N<3)
        return;
    for(int i=0; i< N-1; i++)
    {
        for(int j= i+1; j<N; j++)
        {
            if(pdata[i]> pdata[j])
            {
                int t = pdata[i];
                pdata[i] = pdata[j];
                pdata[j] = t;
            }
        }
    }
    //searching
    int mmax =2;
    int * saving = new int [N];
    int * saved = new int [N];
    for(int f= 0; f<N-2; f++)
    {
        int d;
        for(int s = f+1; s< N-1; s++)
        {
            d = pdata[s]-pdata[f];
            int keep = pdata[s];
            int cnt=2;
            for(int t = s+1; t<N; t++)
            {
                if(pdata[t]-keep == d)
                {
                    if(keep == pdata[s])
                    {
                        cout<<pdata[f]<<","<<keep<<",";
                        saving[0] = pdata[f];
                        saving [1] = keep;
                    }
                    cout<<pdata[t]<<",";
                    saving [cnt] = pdata[t];
                    keep = pdata[t];
                    cnt++;
                }
            }
            if(keep != pdata[s])
            {
                cout<<endl;
                if(cnt > mmax)
                {
                    for(int d =0; d<cnt; d++)
                    {
                        saved[d] = saving[d];
                    }
                    mmax = cnt;
                }
            }

        }
    }
    for(int i= 0; i<mmax; i++)
        cout<<saved[i]<<",";
    delete []saving;
    delete []saved;

}

int main()
{
    const int N = 10;
    int p[N] ={1,3,0,5,-1,6,4,3,7,10};
    ArithmeticProgression(p, N);
    return 0;
}
