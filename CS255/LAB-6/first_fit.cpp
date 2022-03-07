// First fit

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    int i, j, total_process, total_block, *process_size, *block_size, *allocated_block, *internal_fragmentation;
    cout << "Enter total process & total block: ";
    cin >> total_process >> total_block;

    // dynamically allocating memory for process size and block size
    process_size = new (nothrow) int(total_process);
    internal_fragmentation = new (nothrow) int(total_process);
    block_size = new (nothrow) int(total_block);
    allocated_block = (int *)calloc(total_process, sizeof(int));

    // taking input for block size
    cout << endl;
    for (i = 0; i < total_block; i++)
    {
        cout << "Size of block " << i + 1 << ": ";
        cin >> block_size[i];
    }

    // taking input for process size
    cout << endl;
    for (i = 0; i < total_process; i++)
    {
        cout << "Size of process " << i + 1 << ": ";
        cin >> process_size[i];
    }

    // first fit calculations
    for (i = 0; i < total_process; i++)
    {
        for (j = 0; j < total_block; j++)
        {
            if (block_size[j] >= process_size[i])
            {
                allocated_block[i] = j + 1;
                internal_fragmentation[i] = block_size[j] - process_size[i];
                block_size[j] -= process_size[i];
                break;
            }
            else
            {
                internal_fragmentation[i] = 0;
            }
        }
    }

    // printing output
    cout << "\nProcess No\t"
         << "Process Size\t"
         << "Allocated in block\t"
         << "Internal Fragmentation" << endl;
    for (i = 0; i < total_process; i++)
    {
        cout << left << setw(16) << i + 1;
        cout << left << setw(16) << process_size[i];
        if (allocated_block[i] != 0)
        {
            cout << left << setw(24) << allocated_block[i];
        }
        else
        {
            cout << left << setw(24) << "Not Allocated";
        }
        cout << left << setw(22) << internal_fragmentation[i] << endl;
    }
}