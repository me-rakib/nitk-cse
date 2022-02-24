// Multiprogramming with a variable number of tasks

#include <iostream>
#define MAX_SIZE 100

using namespace std;

int main()
{
    int i, n = 0, memory_size, temp, required_memory[MAX_SIZE];
    char y_n = 'y';

    cout << "Enter total memory size in bytes: ";
    cin >> memory_size;

    temp = memory_size;

    while (y_n == 'y')
    {
        cout << "\nEnter required memory for process " << n + 1 << " in bytes: ";
        cin >> required_memory[n];
        if (temp >= required_memory[n])
        {
            cout << "Memory is allocated for process " << n + 1 << endl;
            temp -= required_memory[n];
        }
        else
        {
            cout << "Memory is full!" << endl;
            break;
        }
        cout << "Do you have more process? (y/n): ";
        cin >> y_n;
        if (y_n != 'y' || y_n != 'n')
        {
            cout << "\nWrong Input";
            exit(0);
        }

        n++;
    }

    cout << "\nTotal memory: " << memory_size << endl;
    cout << "\nProcess\t\t"
         << "Memory Allocated" << endl;

    for (i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << required_memory[i] << endl;
    }

    cout << "\nTotal memory allocated: " << memory_size - temp << endl;
    cout << "External fragmentation: " << temp << endl;

    return 0;
}