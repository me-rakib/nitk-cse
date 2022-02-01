// First Come First Serve - FCFS
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Process
{
    int pid; // process id
    int at;  // arrival time
    int bt;  // burst time
    int wt;  // waiting time
    int tat; // turnaround time
};

// functions
void sort(vector<Process> &processes, int n);
void waiting_time(vector<Process> &processes, int n);
void turn_around_time(vector<Process> &processes, int n);

int main()
{
    vector<Process> processes;
    int i, j, n, u_at, u_bt;
    float avg_wt = 0, avg_tat = 0;

    cout << "Total process: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter arrival time and burst time: ";
        cin >> u_at >> u_bt;
        processes.push_back({i + 1, u_at, u_bt, 0, 0});
    }

    sort(processes, n);
    waiting_time(processes, n);
    turn_around_time(processes, n);

    cout << "\nFirst Come First Serve - FCFS" << endl;
    cout << "PID\t"
         << "Arrival Time\t"
         << "Burst Time\t"
         << "Waiting Time\t"
         << "Turnaround Time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << left << setw(8) << processes[i].pid;
        cout << left << setw(17) << processes[i].at;
        cout << left << setw(15) << processes[i].bt;
        cout << left << setw(17) << processes[i].wt;
        cout << left << setw(20) << processes[i].tat << endl;
        avg_wt += processes[i].wt;
        avg_tat += processes[i].tat;
    }

    cout << "\nAvg waiting time = " << avg_wt / (float)n << endl;
    cout << "Avg turnaround time = " << avg_tat / (float)n << endl;

    return 0;
}

// calculating turn around time
void turn_around_time(vector<Process> &processes, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        processes[i].tat = processes[i].wt + processes[i].bt;
    }
}

// calculating waiting time
void waiting_time(vector<Process> &processes, int n)
{
    processes[0].wt = 0;
    for (int i = 1; i < n; i++)
    {
        processes[i].wt = processes[i - 1].wt + processes[i - 1].bt;
    }
}

// sorting based on arrival time
void sort(vector<Process> &processes, int n)
{
    Process temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (processes[i].at > processes[j].at)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}