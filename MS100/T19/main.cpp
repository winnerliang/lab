#include <iostream>

using namespace std;

int Fibonacci(int n)
{
    if(n<0)
        return -1;
    else if(n <2 )
        return n;
    int f[2]={0,1};
    while(n>1)
    {
        int sum = f[0]+f[1];
        f[0] = f[1];
        f[1] = sum;
        n--;
    }
    return f[1];
}

int f(int n)
{
    if(n<2)
        return n;
    return f(n-1)+f(n-2);
}

int main()
{
    int i=20;
    cout<< f(i)<<" "<<Fibonacci(i);
    return 0;
}
