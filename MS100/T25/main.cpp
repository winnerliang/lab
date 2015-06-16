#include <iostream>
#include <string.h>

using namespace std;

int continumax(char *out,char *in)
{
    int mmax =0;
    char *saving = in, * keep = NULL;

    while(*in!='\0')
    {
        saving = in;
        while(*in<='9' && *in>='0')
        {
            in++;
        }
        if(in-saving > mmax)
        {
            keep = saving;
            mmax = in-saving;
        }
        in++;
    }
    for(int i=0; i< mmax; i++)
    {
        *out++ = *keep++;
    }
    *out = '\0';
    return mmax;
}

int main()
{
    char in[]="abcd12345ed125ss123456d789";
    char *out = new char [strlen(in)+1];
    cout<<continumax(out, in);
    cout<<" "<<out;

    delete [] out;
    return 0;
}
