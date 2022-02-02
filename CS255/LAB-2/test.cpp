#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Process
{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
};

void print(vector<Process> &pro, int n);

int main()
{
    vector<Process> process;
    int n, i, *bt_remaining, u_at, u_bt, sum_wt = 0, sum_tat = 0;

    cout << "Total Process: ";
    cin >> n;
    bt_remaining = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        cout << "Enter arival time and burst time: ";
        cin >> u_at >> u_bt;
        process.push_back({i + 1, u_at, u_bt, 0, 0});
        bt_remaining[i] = u_bt;
    }

    /*
    0 5
    1 3
    2 4
    4 1
    */

    int completed = 0, current_time = 0, prev = 0, *is_completed = (int *)calloc(n, sizeof(int));

    while (completed != n)
    {
        int id = -1;
        int mn = 10000;

        for (i = 0; i < n; i++)
        {
            if (process[i].at <= current_time && is_completed[i] == 0)
            {
                if (bt_remaining[i] < mn)
                {
                    mn = bt_remaining[i];
                    id = i;
                }
                if (bt_remaining[i] == mn)
                {
                    if (process[i].at < process[id].at)
                    {
                        mn = bt_remaining[i];
                        id = i;
                    }
                }
            }
        }

        if (id != -1)
        {
            bt_remaining[id] -= 1;
            current_time++;

            if (bt_remaining[id] == 0)
            {
                process[id].tat = current_time - process[id].at;
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
    cout << "\nAvg turnaround time = " << sum_tat / (float)n << endl;
    cout << "Avg waiting time = " << sum_wt / (float)n;
    return 0;
}

void print(vector<Process> &pro, int n)
{
    int i;
    cout << "\nShortest Remaining Time First - SRTF" << endl;
    cout << "PID\t"
         << "Arrival Time\t"
         << "Burst Time\t"
         << "Waiting Time\t"
         << "Turnaround Time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << left << setw(8) << pro[i].pid;
        cout << left << setw(17) << pro[i].at;
        cout << left << setw(15) << pro[i].bt;
        cout << left << setw(17) << pro[i].wt;
        cout << left << setw(20) << pro[i].tat << endl;
    }
}

/*
completed = 0
current_time = 0
while(completed != n) {
    find process with minimum burst time among process that are in ready queue at current_time
    if(process found) {

        burst_time = burst_time - 1
        current_time = current_time + 1

        if(burst_time == 0) {
            turnaround_time = current_time - arrival_time
            waiting_time = turnaround_time - burst_time

            mark process as completed
            completed++
        }
    }
    else {
        current_time++
    }
}
*/