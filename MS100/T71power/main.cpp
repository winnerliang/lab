#include <iostream>

using namespace std;

double Power(double base, int exponent)
{
    if(exponent ==0 )
        return 1;
    else if(exponent == 1)
        return base;
    if(exponent %2 ==0 )
    {
        double a = Power(base, exponent/2);
        return a*a;
    }
    else
    {
        double a = Power(base, exponent/2);
        return a*a * base;
    }

}

int main()
{
    cout << Power(-3.4,2) << endl;
    return 0;
}
