// Banker's Algorithom

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    // tr = total resources
    // tp = total process
    int tp, tr, i, j, k;
    cout << "Enter number of process and resources: ";
    cin >> tp >> tr;

    vector<vector<int>> allocated, max;

    // allocated resources
    for (i = 0; i < tp; i++)
    {
        int temp_r;
        vector<int> temp;
        cout << "Enter allocation for P" << i << ": ";
        for (j = 0; j < tr; j++)
        {
            cin >> temp_r;
            temp.push_back(temp_r);
        }
        allocated.push_back(temp);
    }

    // maximum resources needed
    for (i = 0; i < tp; i++)
    {
        int temp_r;
        vector<int> temp;
        cout << "Enter maximum need for P" << i << ": ";
        for (j = 0; j < tr; j++)
        {
            cin >> temp_r;
            temp.push_back(temp_r);
        }
        max.push_back(temp);
    }

    // available resources
    cout << "\nEnter available resources: ";
    vector<int> avail;
    for (i = 0; i < tr; i++)
    {
        int temp;
        cin >> temp;
        avail.push_back(temp);
    }

    // remaining need to successfully execute process
    int *flag_arr, *ans_seq, **need, ind = 0;
    flag_arr = (int *)calloc(tp, sizeof(int));
    ans_seq = (int *)malloc(tp * sizeof(int));

    need = (int **)malloc(tp * sizeof(int *));
    for (i = 0; i < tp; i++)
    {
        need[i] = (int *)malloc(tr * sizeof(int));
    }

    for (i = 0; i < tp; i++)
    {
        for (j = 0; j < tr; j++)
            need[i][j] = max[i][j] - allocated[i][j];
    }

    // deadlock or not
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < tp; i++)
        {
            if (flag_arr[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < tr; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans_seq[ind++] = i;
                    for (y = 0; y < tr; y++)
                        avail[y] += allocated[i][y];
                    flag_arr[i] = 1;
                }
            }
        }
    }

    // if unsafe
    int flag = 1;
    for (i = 0; i < tp; i++)
    {
        if (flag_arr[i] == 0)
        {
            flag = 0;
            cout << "\nBlocked! Unsafe";
            break;
        }
    }

    // if safe
    if (flag == 1)
    {
        cout << "\nNo Deadlock! Sequence of execution: ";
        for (i = 0; i < tp - 1; i++)
        {
            cout << "P" << ans_seq[i] << " -> ";
        }
        cout << "P" << ans_seq[tp - 1];
    }

    return (0);
}
