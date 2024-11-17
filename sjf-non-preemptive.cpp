#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, arrivalTime, burstTime, turnAroundTime, waitingTime;
    bool completed = false;
};

int main() {
    int size;
    cin >> size;
    vector<Process> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i].id = i + 1; 
        cin >> arr[i].arrivalTime >> arr[i].burstTime;
    }
    
    int currTime = 0;
    int completedCount = 0;

    while (completedCount < size) {
        int minIndex = -1;
        int minBurstTime = INT_MAX;

        for (int i = 0; i < size; i++) {
            Process& p = arr[i];
            if (!p.completed && p.arrivalTime <= currTime && p.burstTime < minBurstTime) {
                minBurstTime = p.burstTime;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            currTime++;
        } else {
            Process& p = arr[minIndex];
            currTime += p.burstTime;

            p.turnAroundTime = currTime - p.arrivalTime;
            p.waitingTime = p.turnAroundTime - p.burstTime;

            p.completed = true;
            completedCount++;
        }
    }

    cout << "Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n";
    for (const Process& p: arr) {
        cout << p.id << "\t\t" << p.arrivalTime 
             << "\t\t" << p.burstTime 
             << "\t\t" << p.turnAroundTime 
             << "\t\t" << p.waitingTime << endl;
    }

    return 0;
}