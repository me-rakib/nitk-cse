// bucket sort
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSortAsc(float *arr, int n);
void bucketSortDsc(float *arr, int n);

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    float arr1[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int i, n;
    n = sizeof(arr) / sizeof(arr[0]);
    bucketSortAsc(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
    bucketSortDsc(arr1, n);
    for (i = 0; i < n; i++)
    {
        printf("%f ", arr1[i]);
    }
    return 0;
}

void bucketSortAsc(float *arr, int n)
{
    vector<float> b[n];
    int i, j, bi;
    for (i = 0; i < n; i++)
    {
        bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // sort
    for (i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    // concate
    int ind = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < b[i].size(); j++)
        {
            arr[ind++] = b[i][j];
        }
    }
}

void bucketSortDsc(float *arr, int n)
{
    vector<float> b[n];
    int i, j, bi;
    for (i = 0; i < n; i++)
    {
        bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // sort
    for (i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    // concate
    int ind = 0;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = b[i].size() - 1; j >= 0; j--)
        {
            arr[ind++] = b[i][j];
        }
    }
}
