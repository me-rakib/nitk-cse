// Pre-emptive priority scheduling

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Process
{
    int priority;
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void print(vector<Process> pro, int n);

int main()
{
    vector<Process> process;
    int n, u_at, u_bt, u_priority, *remaining_bt, sum_tat = 0, sum_wt = 0;

    cout << "Total process: ";
    cin >> n;
    remaining_bt = (int *)calloc(n, sizeof(n));

    for (int i = 0; i < n; i++)
    {
        cout << "Enter priority, arrival time and burst time: ";
        cin >> u_priority >> u_at >> u_bt;
        process.push_back({u_priority, i + 1, u_at, u_bt, 0, 0, 0});
        remaining_bt[i] = u_bt;
    }

    /*
    10 0 5
    20 1 4
    30 2 2
    40 4 1
    */

    int id, mx, completed = 0, current_time = 0, *is_completed = (int *)calloc(n, sizeof(int));

    while (completed != n)
    {
        id = -1;
        mx = -1;

        // finding process with highest priority withing current time 
        for (int i = 0; i < n; i++)
        {
            if (process[i].at <= current_time && is_completed[i] == 0)
            {
                if (process[i].priority > mx)
                {
                    mx = process[i].priority;
                    id = i;
                }

                if (process[i].priority == mx)
                {
                    if (process[i].at < process[id].at)
                    {
                        mx = process[i].priority;
                        id = i;
                    }
                }
            }
        }

        // if any process found
        if (id != -1)
        {
            remaining_bt[id] -= 1;
            current_time++;

            if (remaining_bt[id] == 0)
            {
                process[id].ct = current_time;
                process[id].tat = process[id].ct - process[id].at;
                process[id].wt = process[id].tat - process[id].bt;

                sum_tat += process[id].tat;
                sum_wt += process[id].wt;

                is_completed[id] = 1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    print(process, n);

    cout << "\nAvg turnaround time: " << sum_tat / (float)n << endl;
    cout << "Avg waiting time: " << sum_tat / (float)n << endl;
    return 0;
}

void print(vector<Process> pro, int n)
{
    int i;
    cout << "\nPre-emptive Priority Scheduling: " << endl;
    cout << "Priority\t"
         << "PID\t"
         << "Arrival Time\t"
         << "Burst Time\t"
         << "Completion Time  \t"
         << "Waiting Time\t"
         << "Turnaround Time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << left << setw(16) << pro[i].priority;
        cout << left << setw(8) << pro[i].pid;
        cout << left << setw(17) << pro[i].at;
        cout << left << setw(15) << pro[i].bt;
        cout << left << setw(25) << pro[i].ct;
        cout << left << setw(17) << pro[i].wt;
        cout << left << setw(20) << pro[i].tat << endl;
    }
}
