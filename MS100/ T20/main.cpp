#include <iostream>

using namespace std;

int newatoi(const char * str)
{
    bool bit = 0;

    while(*str ==' ')
        str++;
    if (*str=='\0')
        return 0;

    if(*str=='-')
    {
        bit =1;
        str++;
    }
    else if(*str == '+')
        str++;

    int ret =0;
    while(*str<='9' && *str>='0' )
    {
        ret *=10;
        ret+= *str-'0';

        str++;
    }
    if(bit ==1)
        return (-1)*ret;
    else
        return ret;
}

int main()
{
    char str[] = "345";
    cout <<newatoi(str)<< endl;
    return 0;
}
