#include <iostream>
#include <MinStack.h>

using namespace std;

int main()
{
    MinStack test;
    int arrays[] ={5,3,4,1,2};

    for (int i=0; i< 5; i++)
        test.push(arrays[i]);

    for (int i=0; i<5; i++)
    {
        int t = test.min();
        cout<<t<<" ";
        test.pop();
    }
    return 0;
}
