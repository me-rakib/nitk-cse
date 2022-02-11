// Round Robin - RR
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

bool sort_at(Process p1, Process p2);
bool sort_pid(Process p1, Process p2);
void print(vector<Process> pro, int n);

int main()
{
    vector<Process> processes;
    int n, tq, u_at, u_bt, sum_tat = 0, sum_wt = 0, *remaining_bt;

    cout << "Enter total process: ";
    cin >> n;
    cout << "Enter time quantam: ";
    cin >> tq;
    remaining_bt = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time and burst time: ";
        cin >> u_at >> u_bt;
        processes.push_back({i + 1, u_at, u_bt, 0, 0, 0});
        remaining_bt[i] = u_bt;
    }

    /*
    0 5
    1 4
    2 2
    4 1
    */

    // sorting based on arrival time
    sort(processes.begin(), processes.end(), sort_at);

    int id, completed = 0, current_time = 0, *mark = (int *)calloc(1000, sizeof(n));
    mark[0] = 1;
    queue<int> qu;
    qu.push(0);

    while (completed != n)
    {
        id = qu.front();
        qu.pop();

        if (remaining_bt[id] - tq > 0)
        {
            remaining_bt[id] -= tq;
            current_time += tq;
        }

        else
        {
            current_time += remaining_bt[id];
            remaining_bt[id] = 0;
            completed++;

            processes[id].ct = current_time;
            processes[id].tat = processes[id].ct - processes[id].at;
            processes[id].wt = processes[id].tat - processes[id].bt;

            sum_tat += processes[id].tat;
            sum_wt += processes[id].wt;
        }

        for (int i = 1; i < n; i++)
        {
            if (remaining_bt[i] > 0 && processes[i].at <= current_time && mark[i] == 0)
            {
                qu.push(i);
                mark[i] = 1;
            }
        }
        
        if (remaining_bt[id] > 0)
        {
            qu.push(id);
        }
        if (qu.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (remaining_bt[i] > 0)
                {
                    qu.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }

    // sorting based on process id
    sort(processes.begin(), processes.end(), sort_pid);
    print(processes, n);

    cout << "Avg turnaround time: " << sum_tat / (float)n << endl;
    cout << "Avg waiting time: " << sum_wt / (float)n << endl;

    return 0;
}

bool sort_at(Process p1, Process p2)
{
    return p1.at < p2.at;
}

bool sort_pid(Process p1, Process p2)
{
    return p1.pid < p2.pid;
}

void print(vector<Process> pro, int n)
{
    int i;
    cout << "\nRound Robin - RR" << endl;
    cout << "PID\t"
         << "Arrival Time\t"
         << "Burst Time\t"
         << "Completion Time  \t"
         << "Waiting Time\t"
         << "Turnaround Time" << endl;
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
