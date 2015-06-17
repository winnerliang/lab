#include <iostream>
#include <string.h>

using namespace std;

bool Isnum(char c)
{
    return (c>='0' && c<='9')?true:false;
}


char * findstr(char *p, char *des)
{
    int len = strlen(p);

    char *cnt = p;

    int index =0, maxlen=0;
    int saving =0, cntlen=0;

    for(; *cnt!= '\0'; cnt ++)
    {
        if(Isnum(*cnt))
        {
            int t = *cnt-'0';
            saving = cnt-p;
            cntlen = 1;
            cnt++;
            while(Isnum(*cnt) && (*cnt-'0')== t+1)
            {
                t  = *cnt-'0';
                cnt++;
                cntlen++;
            }
            if(cntlen > maxlen)
            {
                index = saving;
                maxlen = cntlen;
            }
        }
    }
    for(int i=0; i< maxlen; i++)
    {
        *des++ = *(index + p);
        p++;
    }
    *des = '\0';
    return des-index;
}

int main()
{

    char p[] ="ads3sl456789DF3456ld345AA";

    int len = strlen(p);

    char * des = new char [len+1];

    cout<< findstr(p, des);

    return 0;
}
