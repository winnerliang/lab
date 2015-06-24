#include <iostream>
#include<stack>
#include <queue>

using namespace std;

void pushstackbottom(stack<int>data, int t)
{
    if(data.empty())
    {
        data.push(t);
        return;
    }
    int et = data.top();
    data.pop();
    pushstackbottom(data, t);
    data.push(et);
}

void reversingstack(stack<int> data)
{
    if(data.empty())
    {
        return;
    }
    int t = data.top();
    data.pop();
    reversingstack(data);
    pushstackbottom(data, t);
}

int main()
{
    stack <int>data;
    for(int i=0; i<10; i++)
    {
        data.push(i+1);
    }
    reversingstack(data);
    for(int i=0; i<10; i++)
    {
        cout<<data.top()<<" ,";
        data.pop();

    }
    return 0;
}
