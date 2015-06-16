#include <iostream>

using namespace std;

int FindOne(int num)
{
    int cnt=0;
    while(num!= 0)
    {
        num &= (num-1);
        cnt++;
    }
    cout<<cnt<<endl;
    return cnt;
}

int main()
{
    FindOne(13);
    return 0;
}
