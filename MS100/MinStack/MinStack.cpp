#include "MinStack.h"


using namespace std;
MinStack::MinStack()
{
    //ctor
}

MinStack::~MinStack()
{
    //dtor
}

int MinStack::min()
{
    return m_sMin.top();
}

void MinStack::pop()
{
    m_sMin.pop();
    m_sStack.pop();
}

void MinStack::push(int data)
{
    if (m_sMin.empty() != true && data > m_sMin.top())
    {
        m_sStack.push(data);
        m_sMin.push(m_sMin.top());
    }
    else
    {
        m_sStack.push(data);
        m_sMin.push(data);
    }
}

