#include <iostream>
#include <string.h>
#include<string>

using namespace std;

int searching(char * str, int halflen)
{
    char *left =str-1, * right = str+1;
    int i;
    for( i=0; i<=halflen; i++,--left,++right )
    {
        if(i==halflen)
            return halflen;
        if(*left!=*right)
            break;
    }
    return i;
}

string longestPalindrome(string s)
{
    //tian chong
    const char *str = s.c_str();
    const char *save =str;
    int len = strlen(str);
    char * nstr = new char [2*len];
    char * pCnt = nstr;
    for(; *save!= '\0'; save++)
    {
        *pCnt++ = *save;
        *pCnt++ = 1;
    }
    --pCnt;
    *pCnt = '\0';
    //cout<<nstr<<"--"<<strlen(nstr)<<endl;

    int mmax = searching(nstr+len-1, len-1);
    int point = len -1 -mmax;
    if(mmax %2== (len-1)%2)
        mmax++;
    else
        point++;

    point = ((len-1)%2 == mmax %2) ? point : point+1;

    for(int i=1; i<len; i++)
    {
        int index = len-1-i;

        int m1 = searching(nstr+len-1+i, index);
        int p1 = len-1+i-m1;
        if(index % 2 == m1 % 2)
            m1++;
        else
            p1++;
        int m2 = searching(nstr+index, index);
        int p2 = index -m2;
        if(index % 2 == m2 % 2)
            m2++;
        else
            p2++;
        int m = (m2 > m1)? m2:m1;
        int extpoint = (m2>m1)?p2:p1;

        if(m>mmax)
            point= extpoint;
        mmax = (m > mmax)? m:mmax;
    }
    //cout<<point <<endl;
    string ss;
    for(int i=0; i<mmax; i++)
        ss.push_back( *(str+point/2 +i));
    //cout<<endl;
    return ss;
}

/*
error!
"
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababababababababababababababab
abababababababababababababababababababa"
*/
/*
"
321
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210012321001232100123210012321001232100123210
012321001232100123210123210012321001232100123210123"

*/


int main()
{
    string str("google") ;


    cout<<longestPalindrome(str)<<endl;
    cout << str << endl;

    return 0;
}
