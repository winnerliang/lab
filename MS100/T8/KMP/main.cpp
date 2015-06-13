#include <iostream>
#include <string.h>

using namespace std;

int * GetNext(char *p, int * next)
{
    int j= 0, k=-1;
    next[0] = k;
    while (j<strlen(p)-1)
    {
        if(k ==-1 || p[k]== p[j])
        {
            k++;
            j++;
            if(p[j] != p[k])
                next[j] = k;
            else
                next[j] =next[k];
        }
        else
            k = next[k];
    }
    return next;
}

int KMP(char *s, char *p)
{
    int slen= strlen(s), plen(strlen(p));

    int i=0, j=0;

    int * next = new int[plen];
    next = GetNext(p, next);

    while(i<slen&& j<plen)
    {
        if(j==-1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    delete []next;
    if(j == plen)return i-j;
    else return -1;
}

int main()
{
    char s[] ="BBC ABCDAB ABCDABCDABDE";
    char p[]= "ABCDABD";
    //char p[]= "ABAB";
    cout<< KMP(s, p);
    return 0;
}
