#include <iostream>
using namespace std;

template <class T, int max>
int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < m)
        {
            m = arr[i];
        }
    }
    return m;
}

int main()
{
    int arr1[] = {10, 20, 15, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << arrMin<int, 1000>(arr1, n1) << endl;
    cout << arrMin<int, 10>(arr2, n2) << endl;
    return 0;
}