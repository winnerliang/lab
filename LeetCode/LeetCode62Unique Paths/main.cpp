#include <iostream>

using namespace std;

void findpath(const int m, const int n, int cntm, int cntn, int &counts)
{
    if(m == cntm && n == cntn)
    {
        counts++;
        return;
    }
    if(cntm < m)
    {
        cntm++;
        findpath(m, n, cntm, cntn, counts);
        cntm--;
    }
    if(cntn < n)
    {
        cntn++;
        findpath(m, n, cntm, cntn, counts);
        cntn--;
    }
}
/*
int uniquePaths(int m, int n) {
    int counts =0;
    findpath(m, n, 0, 0, counts);

    return counts;
}
*/

int uniquePaths(int m, int n) {
    int bottom = m+n-2;
    int top = (m>n)?n:m;
    top--;
    if(top == 0 )
        return 1;

    double sum = bottom;
    for(int i=1; i<top; i++)
    {
        sum *= (bottom - i);
    }

    //cout<<sum;

    for(int i=1; i<top+1; i++)
        sum /= i;
    return (int)sum;
}

int main()
{
    cout << uniquePaths(2, 1) << endl;
    return 0;
}
