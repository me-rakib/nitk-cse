#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_SIZE 100
using namespace std;

int temp_array_contining_comb[MAX_SIZE];
vector<vector<int>> combinations;

void get_combinations(int target, int A[], int n, int ind);
int main()
{
    freopen("input_4.txt", "r", stdin);
    freopen("output_4.txt", "w", stdout);
    
    int n, target, *A = NULL, i, j;
    cin >> n;                 //total element
    A = new (nothrow) int[n]; //allocating memory
    for (i = 0; i < n; i++)
    {
        cin >> A[i]; //taking input for array
    }
    sort(A, A + n);
    cin >> target; // getting target number
    get_combinations(target, A, n, 0);

    //printing unique combinitation
    int com_size = combinations.size();
    for (i = 0; i < com_size; i++)
    {
        int com_col_size = combinations[i].size();
        sort(combinations[i].begin(), combinations[i].end());

        for (j = 0; j < com_size; j++)
        {
            if (combinations[i] == combinations[j])
            {
                break;
            }
        }
        if (i == j)
        {
            for (j = 0; j < com_col_size; j++)
            {
                printf("%d ", combinations[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

//get combinations and store in combinations
void get_combinations(int target, int A[], int n, int ind)
{

    if (target == 0)
    {
        vector<int> temp;
        for (int i = 0; i < ind; i++)
        {
            temp.push_back(temp_array_contining_comb[i]);
        }
        combinations.push_back(temp);
        return;
    }
    else if (target < 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            temp_array_contining_comb[ind] = A[i];
            get_combinations(target - A[i], A, n, ind + 1);
        }
    }
}