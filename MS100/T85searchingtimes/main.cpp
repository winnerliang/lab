#include <iostream>
#include<string.h>

using namespace std;

void donext(char *p, int *next)
{
    int j=0, k=-1;
    int len = strlen(p);

    next[j]=k;

    while(j<len-1)
    {
        if(k==-1 || p[j] == p[k])
        {
            j++;
            k++;
            if(p[j]!= p[k])
                next[j] =k;
            else
                next[j] =next[k];
        }
        else
        {
            k =next[k];
        }
    }
}

int searchingtimes(char *s, char *p)
{
    int cnt=0;

    int plen = strlen(p);
    int slen = strlen(s);
    int *next = new int[plen];

    donext(p, next);

    int i=0, j=0;
    while(i<slen)
    {
        if(j==-1 || s[i]==p[j])
        {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
        if(j == plen)
        {
            j = 0;
            cnt++;
        }
    }
    delete[]next;
    return cnt;
}

int main()
{
    char s[]="asderwsde", p[] = "re";

    cout<< searchingtimes(s, p);
    return 0;
}
