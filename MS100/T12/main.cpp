#include <iostream>

using namespace std;

class sum
{
    static int cnt;
    static int sumdo;
public:
    sum()
    {
        cnt ++;
        sumdo += cnt;
    }
    void disp()
    {
        cout<<cnt<<" ";
        cout<<sumdo;
    }
};

int sum::cnt =0;
int sum::sumdo =0;


typedef int (* fun)(int n);
int sumf1(int n)
{
    return 0;
}

int sumf2(int n)
{
    static fun test[2] ={sumf1, sumf2};
    return n + test[!!n](n-1);
}

int main()
{
    cout<<sumf2(100);
    return 0;
}
