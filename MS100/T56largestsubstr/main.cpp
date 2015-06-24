#include <iostream>
#include <string.h>

using namespace std;

char *substring(char * xstr, char * ystr, char * desstr)
{
    int xlen =strlen(xstr), ylen = strlen(ystr);
    int *cntsub = new int [xlen]();

    for(int i=0; i<xlen; i++)
    {
        //cout<<"("<<cntsub1[i]<<", "<<cntsub2[i]<<") ,";
    }
    //cout<<endl;
    for(int i=0; i<ylen; i++)
    {
        int t=0;
        for(int j=0; j<xlen; j++)
        {
            if(j==0)
            {
                if(cntsub[0]==1 || xstr[j]==ystr[i])
                    cntsub[0]=1;
                else
                    cntsub[0]=0;
                t = cntsub[0];
            }
            else
            {
                cntsub[j-1] = t;
                if( xstr[j] == ystr[i])
                {
                    t = cntsub[j] + 1;
                }
                else
                    t = cntsub[j];

                if( cntsub[j] < cntsub[j-1])
                    t =cntsub[j-1];
            }
        }
        cntsub[xlen-1] =t;
    }
    //cout<< cntsub2[xlen-1]<<endl;

    int index=0;
    for(int i=0; i<xlen; i++)
    {
        if( i ==0  && cntsub[i]== 1)
        {
            desstr[index++]=xstr[i];
        }
        else if(i>0 && cntsub[i] == cntsub[i-1]+1){
            desstr[index++]=xstr[i];
        }
    }
    desstr[index]='\0';
    delete [] cntsub;
    return desstr;
}

int main()
{
    char xstr[] ="BDCABA", ystr[] = "ABCBDAB";

    char *desstr = new char [strlen(xstr)+1];
    desstr = substring(xstr, ystr, desstr);

    cout<<strlen(desstr)<<endl<<desstr<<endl;

    delete[] desstr;
    return 0;
}
