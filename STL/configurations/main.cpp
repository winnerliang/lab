#include <iostream>

using namespace std;

template <typename T>
class testClass
{
    public :
    static int _data;
};

template<typename T > int testClass <T>::_data =1;
//template<typename T > int testClass <char>::_data =2;

int main()
{
    cout<<testClass<int>::_data<<endl;
    cout<<testClass<char>::_data<<endl;

    testClass<int> obj1;
    testClass<char> obj2;

    cout<< obj1._data<<endl;
    cout<<obj2._data<<endl;

    return 0;
}
