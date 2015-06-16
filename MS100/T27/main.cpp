#include <iostream>

using namespace std;

int Jump(int n)
{
    //f(n) = f(n-1)+ f(n-2)
    int cnt [2] ={1,2};

    if(n<1)
        return 0;
    else if(n<3)
        return cnt[n-1];
    for(; n>2; n--)
    {
        int sum = cnt[0]+cnt[1];
        cnt[0]= cnt[1];
        cnt[1]= sum;
    }
    return cnt[1];
}

int main()
{
    cout << Jump(4) << endl;
    return 0;
}
