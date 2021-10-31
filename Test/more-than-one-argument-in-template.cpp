#include <iostream>
using namespace std;

template <class T, class U>
class A
{
private:
    T x;
    U y;

public:
    A()
    {
        cout << "Constructor called" << endl;
    }
};

int main()
{
    A<char, int> a;
    A<int, float> b;
    return 0;
}