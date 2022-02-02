// SJF - Shortest Job First
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// Structure for storing process info
struct Process
{
    int pid; // process id
    int at;  // arrival time
    int bt;  // burst time
    int tat; // turn around time
    int wt;  // waiting time
    int ct;  // completion time
};

// functions
void print(vector<Process> &pro, int n);

int main()
{
    vector<Process> processes; // array of process
    int n, i, u_at, u_bt, sum_wt = 0, sum_tat = 0;

    // taking inputs
    cout << "Total process: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter arrival time & burst time: ";
        cin >> u_at >> u_bt;
        processes.push_back({i + 1, u_at, u_bt, 0, 0, 0});
    }

    /*
    1 3
    2 4
    1 2
    4 4
    */

    int completed = 0, current_time = 0;
    int *is_completed = (int *)calloc(n, sizeof(int));

    while (completed != n)
    {
        int id = -1;
        int mn = 100000;

        // find process with minimum burst time
        for (i = 0; i < n; i++)
        {
            if (processes[i].at <= current_time && is_completed[i] == 0)
            {
                if (processes[i].bt < mn)
                {
                    mn = processes[i].bt;
                    id = i;
                }
                if (processes[i].bt == mn)
                {
                    if (processes[i].at < processes[id].at)
                    {
                        mn = processes[i].bt;
                        id = i;
                    }
                }
            }
        }

        // if process found with minimum burst time
        if (id != -1)
        {
            processes[id].ct = current_time + processes[id].bt;
            processes[id].tat = processes[id].ct - processes[id].at;
            processes[id].wt = processes[id].tat - processes[id].bt;

            sum_tat += processes[id].tat;
            sum_wt += processes[id].wt;

            is_completed[id] = 1;
            completed++;
            current_time = processes[id].ct;
        }
        else
        {
            current_time++;
        }
    }

    print(processes, n);

    cout << "\nAvg turnaround time = " << sum_tat / (float)n << endl;
    cout << "Avg waiting time = " << sum_wt / (float)n << endl;

    return 0;
}

// function to print processes
void print(vector<Process> &pro, int n)
{
    cout << "\nShortest Job First - SJF" << endl;
    cout << "PID\t"
         << "Arrival Time\t"
         << "Burst Time\t"
         << "Completion Time  \t"
         << "Waiting Time\t"
         << "Turnaround Time" << endl;
    int i;
    for (i = 0; i < n; i++)
    {
        cout << left << setw(8) << pro[i].pid;
        cout << left << setw(17) << pro[i].at;
        cout << left << setw(15) << pro[i].bt;
        cout << left << setw(25) << pro[i].ct;
        cout << left << setw(17) << pro[i].wt;
        cout << left << setw(20) << pro[i].tat << endl;
    }
}