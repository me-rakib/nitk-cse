// Banker's Algorithom

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{

    int i, j, k, tr, tp, temp_num;
    cout << "Enter number of process and resources: ";
    cin >> tp >> tr;

    vector<vector<int>> allocated, max_need;
    vector<int> temp;

    // allocated resources
    for (i = 0; i < tp; i++)
    {
        cout << "Enter allocated for P" << i << ": ";
        for (j = 0; j < tr; j++)
        {
            cin >> temp_num;
            temp.push_back(temp_num);
        }
        allocated.push_back(temp);
    }

    
    for (i = 0; i < tp; i++)
    {
        cout << "Enter maximum resource for P" << i << ": ";
        for (j = 0; j < tr; j++)
        {
            cin >> temp_num;
            temp.push_back(temp_num);
        }
        max_need.push_back(temp);
    }

    
    vector<int> available_resources;
    cout << "\nEnter available resources: ";
    for (i = 0; i < tr; i++)
    {
        cin >> temp_num;
        available_resources.push_back(temp_num);
    }

    
    int **rem_need; 
    rem_need = (int **)malloc(tp * sizeof(int *));
	for (i = 0; i < tp; i++)
	{
		rem_need[i] = (int *)malloc(tr * sizeof(int));
	}
    for (i = 0; i < tp; i++)
	{
		for (j = 0; j < tr; j++)
		{
			rem_need[i][j] = max_need[i][j] - allocated[i][j];
		}
	}


    
    int *flag_arr, flag, *ans_seq, indx = 0;
    flag_arr = (int *)calloc(tp, sizeof(int));
    ans_seq = (int *)malloc(tp * sizeof(int));

    for (k = 0; k < tp; k++)
    {
        for (i = 0; i < tp; i++)
        {
            if (flag_arr[i] == 0)
            {
                flag = 0;
                for (j = 0; j < tr; j++)
                {
                    if (rem_need[i][j] > available_resources[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    int z;
                    flag_arr[i] = 1;
                    ans_seq[indx++] = i;
                    for (z = 0; z < tr; z++)
                    {
                        available_resources[z] += allocated[i][z];
                    }
                }
            }
        }
    }

    flag = 1;
    for (i = 0; i < tp; i++)
    {
        if (flag_arr[i] == 0)
        {
            flag = 0;
            cout << "\nBlocked! Unsafe";
            break;
        }
    }

    if (flag == 1)
    {
        cout << "\nNo Deadlock! Sequence of execution: ";
        for (i = 0; i < tp - 1; i++)
        {
            cout << "P" << ans_seq[i] << " -> ";
        }
        cout << "P" << ans_seq[tp - 1];
    }

    return 0;
}