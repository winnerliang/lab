#include <iostream>

using namespace std;

int GetFinally(int n, int m)
{
    if(n==1)
    {
        return 0;
    }
    return (GetFinally(n-1, m)+ m)%n;
}

int main()
{
    cout <<GetFinally(5, 3);
    return 0;
}
