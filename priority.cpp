#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, burstTime, priority, turnAroundTime, waitingTime;
    bool operator < (const Process& other) const {
        return priority > other.priority;
    }
};

int main() {
    int size;
    cin >> size;
    vector<Process> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i].id = i + 1;
        cin >> arr[i].burstTime >> arr[i].priority;
    }
    
    sort(arr.begin(), arr.end());
    
    int currTime = 0;
    for (int i = 0; i < size; i++) {
        currTime += arr[i].burstTime;
        arr[i].turnAroundTime = currTime;
        arr[i].waitingTime = arr[i].turnAroundTime - arr[i].burstTime;
    }

    for (const Process& p: arr) {
        cout << "ID: " << p.id
             << ", Priority: " << p.priority 
             << ", Burst Time: " << p.burstTime 
             << ", Turnaround Time: " << p.turnAroundTime 
             << ", Waiting Time: " << p.waitingTime << endl;
    }

    return 0;
}