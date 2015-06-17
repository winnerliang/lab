#include <iostream>

using namespace std;

char * deletechar(char *str, char c)
{
    int cnt=0, savingcnt=0;

    for(; *(str+cnt)!= '\0'; cnt++)
        if(str[cnt]!= c)
            str[savingcnt++] = str[cnt];
    str[savingcnt] = '\0';
    return str;
}

int main()
{
    char str[] = "asdfsafsafsdgad";
    cout<<str<<endl;
    char c ='d';
    deletechar(str, c);

    cout<<str;
    return 0;
}
