#include <iostream>
#include<string.h>

using namespace std;

void rotating(char * str, int len)
{
    char *start = str, *eend = str+len-1;
    while(start<eend)
    {
        *start ^= *eend;
        *eend ^= *start;
        *start ^= *eend;
        start++;
        eend--;
    }
}

void leftrotating(char *str, int n)
{
    int len = strlen(str);
    rotating(str, len );
    //cout<<str<<endl;
    rotating(str, len - n);
    //cout<<str<<endl;
    rotating(str+len - n, strlen(str + len - n));
    //cout<<str<<endl;

}
int main()
{
    char str[]="abcdef";
    //cout<<str<<endl;
    leftrotating(str, 5);
    //cout<<str<<endl;
    return 0;
}
