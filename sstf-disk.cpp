#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> requests = {98, 183, 37, 124, 14, 122, 65, 67};
    vector<bool> visited(requests.size(), false);
    int head = 53;
    int movement = 0;

    int completedCount = 0;
    while (completedCount++ < requests.size()) {
        int minSeekTime = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < requests.size(); i++) {
            if (!visited[i] && abs(head - requests[i]) < minSeekTime) {
                minSeekTime = abs(head - requests[i]);
                minIndex = i;
            }
        }
        movement += minSeekTime;
        head = requests[minIndex];
        visited[minIndex] = true;
    }

    cout << "Total head movement is: " << movement;
}