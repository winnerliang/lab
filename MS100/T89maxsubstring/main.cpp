#include <iostream>
#include <string.h>

using namespace std;

char * Getmaxsubstring(char * pstr, char *qstr, char *des)
{
    int maxsub=0, index=0;
    if(pstr==NULL || qstr ==NULL )
    {
        des =  NULL;
        return des;
    }
    int N = strlen(pstr);
    int *keeps = new int [N];
    for(int i=0; i<N ; i++)
        keeps[i]=0;

    for(int j = 0; *(qstr+j) != '\0'; j++)
    {
        for(int i = N -1; i >= 0; i--)
        {
            if(pstr[i] == qstr[j])
            {
                if(i==0)
                    keeps[i]=1;
                else
                    keeps[i] =keeps[i-1]+1;
                if(keeps[i] > maxsub)
                {
                    maxsub = keeps[i];
                    index = i-maxsub+1;
                }
            }
            else
                keeps[i]=0;
        }
    }
    int k=0;
    for( k= 0; k< maxsub ; k++)
    {
        des[k]= pstr[k+index];
    }
    des[k] = '\0';
    delete[]keeps;
    return des;
}

int main()
{
    char ps[]="abractyeyt";
    char qs[] ="dgdsaeactyey";

    int pl = strlen(ps), ql = strlen(qs);
    int len = pl < ql ?pl:ql;

    char *des = new char [len+1];
    cout<< Getmaxsubstring(ps, qs, des);

    delete [] des;
    return 0;
}
