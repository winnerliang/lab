#include <iostream>

using namespace std;

int movechar(char * str)
{
    if(str==NULL)
        return 0;

    int len=0;
    for(; *(str+len)!= '\0'; len++);

    int index=len-1, cnt=len-1;

    for(; cnt>=0; cnt--)
    {
        if(*(str+cnt)!= '*')
        {
            *(str+index--) = *(str+cnt);
        }
    }
    for(int i=0; i<index+1; i++)
        *(str+i)='*';
    return index+1;
}

int main()
{

    char s [] ="ab**cd**e*12";

    cout << movechar(s)<< ", "<<s;
    return 0;
}
