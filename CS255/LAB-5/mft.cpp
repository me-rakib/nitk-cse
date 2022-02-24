// multiprogramming with a fixed number of tasks
#include <iostream>
#include <iomanip>
#define MAX_SIZE 100

using namespace std;

/*
Input -> 1000, 300, 5, 275, 400, 290, 293, 100
*/

int main()
{
    int i, process = 0, memory_size, block_size, total_block, external_fragmentation, enternal_fragmentation = 0, total_process, required_memory[MAX_SIZE];

    cout << "Enter total memory size in bytes: ";
    cin >> memory_size;

    cout << "Enter block size in bytes: ";
    cin >> block_size;

    total_block = memory_size / block_size;
    external_fragmentation = memory_size % block_size;

    cout << "\nEnter total process: ";
    cin >> total_process;

    for (i = 0; i < total_process; i++)
    {
        cout << "Enter required memory for process " << i + 1 << " in bytes: ";
        cin >> required_memory[i];
    }

    cout << "\nAvailable block: " << total_block << endl;

    cout << "\n" <<left << setw(15) << "Process No" <<left << setw(20) << "Required Memory" << left << setw(15) << "Allocated" << left << setw(25) <<"Enternal Fragmentation" << endl;

    for (i = 0; i < total_process && process < total_block; i++)
    {
        cout << left << setw(15) << i + 1 << left << setw(20) << required_memory[i];
        if (block_size >= required_memory[i])
        {
            cout << left << setw(15) << "YES " << left << setw(25) << block_size - required_memory[i] << endl;
            process++;
            enternal_fragmentation += (block_size - required_memory[i]);
        }
        else
        {
            cout << left << setw(15) << "NO" << left << setw(25) << "--" << endl;
        }
    }

    if (i < total_process) 
    {
        cout << "\nMemory is already full! Remaining process cannot be stored in Memory." << endl;
    }

    cout << "\nEnternal Fragmentation: " << enternal_fragmentation << endl;
    cout << "External Fragmentation: " << external_fragmentation << endl;

    return 0;
}