#include <iostream>
#include <string.h>

using namespace std;

char * deletestring(char *rawstr, char *delstr)
{

    if(rawstr == NULL )
        return NULL;
    if(delstr == NULL)
        return rawstr;

    char * Flag = new char[256];

    memset(Flag, 0, 256);

    for(char * cnt = delstr; *cnt!='\0';cnt++)
    {
        Flag[*cnt]=1;
    }
    int index =0;
    for(char *cnt =rawstr; *cnt!='\0'; cnt++)
    {
        if(Flag[*cnt]==0)
        {
            rawstr[index++]= *cnt;
        }
    }
    rawstr[index]='\0';

    delete [] Flag;
    cout<<rawstr;
    return rawstr;
}

int main()
{
    char rawstr[] ="They are students.", delstr[]= "aeiou";

    deletestring(rawstr, delstr);
    return 0;
}
