#include <bits/stdc++.h>
using namespace std;

struct Process {
    int arrivalTime, burstTime, turnAroundTime, waitingTime;
    bool operator < (const Process& other) const {
        return arrivalTime < other.arrivalTime;
    }
};

int main() {
    int size;
    cin >> size;
    vector<Process> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i].arrivalTime >> arr[i].burstTime;
    }
    
    sort(arr.begin(), arr.end());
    
    int currTime = 0;
    for (int i = 0; i < size; i++) {
        if (currTime < arr[i].arrivalTime) {
            currTime = arr[i].arrivalTime; 
        }
        
        currTime += arr[i].burstTime;
        arr[i].turnAroundTime = currTime - arr[i].arrivalTime;
        arr[i].waitingTime = arr[i].turnAroundTime - arr[i].burstTime;
        
    }

    for (const Process& p: arr) {
        cout << "Arrival Time: " << p.arrivalTime 
             << ", Burst Time: " << p.burstTime 
             << ", Turnaround Time: " << p.turnAroundTime 
             << ", Waiting Time: " << p.waitingTime << endl;
    }

    return 0;
}