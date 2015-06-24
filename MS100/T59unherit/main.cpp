#include <iostream>

using namespace std;

class test
{
    int m_val;
    test(int val):m_val(val){}

public:
    friend void create(int val);

};

class derived :public test{
    int m_id;
public:

    derived(int id, int val):test(val), m_id(id){}
};

int main()
{
    derived dd(10,20);
    return 0;
}
