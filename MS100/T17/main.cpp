#include <iostream>

using namespace std;

char Serchingchar(char* str)
{
    char table[256];
    for(int i=0; i<256; i++)
        table[i]=0;
    char * cnt = str;
    while(*cnt!= '\0')
    {
        table[*cnt++]++;
    }
    for(;*str!='\0';str++)
    {
        if(table[*str]== 1)
            return *str;
    }
    return -1;
}

int main()
{
    char str[]="abaccdeff";
    cout << Serchingchar(str);
    return 0;
}
