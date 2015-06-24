#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <class T>
class myqueue
{
    stack<T> In, Out;
    void dothing()
    {
        while(!In.empty())
        {
            T t= In.top();
            In.pop();
            Out.push(t);
        }
    }
public:
    void pop()
    {
        if(!Out.empty())
        {
            Out.pop();
            return;
        }
        if(!In.empty())
        {
            dothing();
            Out.pop();
            return;
        }
        cout<< "error!"<<endl;
    }
    T front()
    {
        if(!Out.empty())
        {
            return Out.top();
        }
        if(!In.empty())
        {
            dothing();
            return Out.top();
        }
        cout<<" error!"<<endl;
        return -1;
    }
    void push(T t)
    {
        if(In.empty() && Out.empty())
        {
            Out.push(t);
            return;
        }
        In.push(t);
    }
};

template<class T>
class mystack
{
    queue<T> In, Out;
public:

    void push(T t)
    {
        if(!In.empty())
        {
            In.push(t);
            return;
        }
        Out.push(t);

    }
    T top()
    {
        if(In.size()>0)
        {
            T t;
            while(!In.empty())
            {
                t = In.front();
                In.pop();
                Out.push(t);
            }
            return t;
        }
        T t;
        while(!Out.empty())
        {
            t = Out.front();
            Out.pop();
            In.push(t);
        }
        return t;
    }

    void pop()
    {
        if(In.empty())
        {
            cout<<"error! "<<endl;
            return;
        }
        else
        {
            T t;
            while(In.size()>1)
            {
                t = In.front();
                In.pop();
                Out.push(t);
            }
            In.pop();
            return;
        }
        if(Out.empty())
        {
            cout<<"error! "<<endl;
            return;
        }
        else
        {
            T t;
            while(Out.size()>1)
            {
                t = Out.front();
                Out.pop();
                In.push(t);
            }
            Out.pop();
        }
    }

};

int main()
{
/*
    myqueue <int> mq;

    for(int i=0; i<10; i++)
        mq.push(i+1);
    for(int i=0; i<15; i++)
    {
        cout<<mq.front()<<", ";
        mq.pop();
        if(i==5)
        {
            for(int i=0; i<5;i++)
            {
                mq.push(i+10);
            }
        }

    }
    */

    mystack <int> ms;

    for(int i=0; i<10; i++)
        ms.push(i+1);
    for(int i=0; i<15; i++)
    {
        cout<<ms.top()<<", ";
        ms.pop();
        if(i==5)
        {
            for(int i=0; i<5;i++)
            {
                ms.push(i+10);
            }
        }

    }
    return 0;
}
