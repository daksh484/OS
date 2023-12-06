WITHOUT TIME ARRIVAL
#include <iostream>
using namespace std;

void fcfs(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];

    // Calculate waiting time for the first process
    waiting_time[0] = 0;

    // Calculate waiting time for the remaining processes
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround time for all processes
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Display the results
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n];
    int burst_time[n];

    cout << "Enter the burst times for each process:" << endl;
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
    }

    fcfs(processes, n, burst_time);

    return 0;
