#include <iostream>
#include<string.h>

using namespace std;

void Reversingstr(char *str, int right)
{
    int n = strlen(str);
    if (right > n )
        return;
    char * lindex = str, *rindex = str+right-1;
    while(lindex < rindex)
    {
        *lindex ^= *rindex;
        *rindex ^= *lindex;
        *lindex ^= *rindex;
        lindex++;
        rindex--;
    }
}

void Reversingword(char * str)
{
    int right =0, left =0;

    Reversingstr(str, strlen(str));
    while(str[right]!= '\0')
    {
        while(str[right]!= '\0' && str[right]!=' ')
            right++;
        Reversingstr(str+ left, right);
        while( str[right]==' ')
            right++;
        left = right;
    }
}

int main()
{
    char str[]="I am   a   student.";

    //Reversingstr(str, strlen(str));

    Reversingword(str);

    cout<<str;
    return 0;
}
