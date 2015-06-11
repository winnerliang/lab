#ifndef MINSTACK_H
#define MINSTACK_H
#include <stack>

class MinStack
{
    public:
        int min();
        void pop();
        void push(int data);
        MinStack();
        virtual ~MinStack();
    protected:
    private:
        std::stack <int> m_sMin;
        std::stack <int> m_sStack;
};

#endif // MINSTACK_H
