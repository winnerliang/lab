#include <iostream>
#include <string.h>

using namespace std;

bool Ishuiwen(const char *pstr)
{
    int len = strlen(pstr);

    const char * pend = pstr+len-1;
    while(pstr<pend)
    {
        if(*pstr!= *pend)
            return false;
        pstr++;
        pend--;
    }
    return true;
}

bool IsIncreasing(int * a, int N)
{
    int f = *a;

    if(N<2)
        return true;

    int *s = a+1;
    for(int i=1; i<N; i++)
    {
        if(f>a[i])
            return false;
    }
    return IsIncreasing(s, N-1);
}
int main()
{
    int q[]={1,2,3,4,6,5};
    cout<<IsIncreasing(q,6);

    return 0;
}
