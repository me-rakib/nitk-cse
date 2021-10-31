#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    char arr[] = {'z', 'a', 'x', 'c', 'k'};
    int i, n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort<char>(arr, n);
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}