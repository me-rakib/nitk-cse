#include <iostream>
using namespace std;
int main()
{
    // redirecting input and output stream
    // from input_1.txt to output_1.txt
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int n, i, *A = NULL, *pre_A_i = NULL, *after_A_i = NULL;
    cin >> n;

    //dynamic memory allocation
    A = new (nothrow) int[n];
    pre_A_i = new (nothrow) int[n];
    after_A_i = new (nothrow) int[n];

    //taking input and assigning value
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    pre_A_i[0] = 1;
    after_A_i[n - 1] = 1;

    // calculation let A[] = {1,2,3,4,5}
    for (i = 1; i < n; i++)
    {
        //pre_A_i[] = {1, 1, 2, 6, 24}
        pre_A_i[i] = pre_A_i[i - 1] * A[i - 1];
        // after_A_i[] = {120, 60, 20, 5, 1}
        after_A_i[n - i - 1] = after_A_i[n - i] * A[n - i];
    }
    for (i = 0; i < n; i++)
    {
        cout << pre_A_i[i] * after_A_i[i] << " ";
    }
    delete[] A;
    delete[] pre_A_i;
    delete[] after_A_i;
    return 0;
}
