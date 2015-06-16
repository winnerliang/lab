#include <iostream>

using namespace std;

char *strcpy(char * strDest, const char * strSrc)
{
    int len=0;
    for(;*(strSrc+len)!='\0';len++);

    long dec = (strDest > strSrc)?strDest - strSrc: strSrc -strDest;

    if(strDest > strSrc && dec < len)
    {
        const char *str1 = strSrc + len;
        char *str2 = strDest+len;
        while(str1>= strSrc)
            *str2-- = *str1--;
        return strDest;
    }
    while(*strSrc!= '\0')
        *strDest++= * strSrc++;
    *strDest='\0';
    return strDest-len;
}

int main()
{
    char p[]="aadsfasfdas";

    int len = 0;
    while(*(p+len)!='\0')
        len++;

    char *q = new char [len+1];

    cout<< strcpy(q, p);


    delete []q;
    return 0;
}
