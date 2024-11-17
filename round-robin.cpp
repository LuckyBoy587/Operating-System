#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, burstTime, remainingTime, turnAroundTime, waitingTime;
};

int main() {
    int size, TQ;
    cin >> size >> TQ;
    vector<Process> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i].id = i + 1;
        cin >> arr[i].burstTime;
        arr[i].remainingTime = arr[i].burstTime;
    }
    
    queue<int> q;
    for (int i = 0; i < size; i++) q.push(i);
    
    int currTime = 0;
    while(!q.empty()) {
        int index = q.front();
        Process& curr = arr[index];
        q.pop();

        if (curr.remainingTime > TQ) {
            currTime += TQ;
            curr.remainingTime -= TQ;
            q.push(index);
        } else {
            currTime += curr.remainingTime;
            curr.remainingTime = 0;
            curr.turnAroundTime = currTime - curr.burstTime;
            curr.waitingTime = curr.turnAroundTime - curr.burstTime;
        }
    }

    for (const Process& p: arr) {
        cout << "ID: " << p.id
             << ", Burst Time: " << p.burstTime 
             << ", Turnaround Time: " << p.turnAroundTime 
             << ", Waiting Time: " << p.waitingTime << endl;
    }

    return 0;
}