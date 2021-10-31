#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <class T>
Array<T>::Array(T arr[], int s)
{
    ptr = new (nothrow) int[s];
    size = s;
    for (int i = 0; i < size; i++)
    {
        ptr[i] = arr[i];
    }
}

template <class T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> A(arr, 5);
    A.print();
    return 0;
}