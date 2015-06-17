#include <iostream>
#include <stdlib.h>
#include<string.h>

using namespace std;

char * searchingdiff(char *str, char *des)
{
    int * dic = (int *)malloc(256*sizeof(int));
    memset(dic, 0 , 256);

    char *p = str, *q = des;

    for(; *p!= '\0';p++)
        dic[*p]++;
    for(; *str!='\0';str++)
        if(dic[*str]>1)
        {
            *des++ = *str;
            dic[*str]=0;
        }

    *des='\0';

    free(dic);
    return q;
}

int main()
{
    char str[] = "ad1es23ad32e4s", des[30];
    cout<<searchingdiff(str, des);
    return 0;
}
