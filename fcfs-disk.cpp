#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> requests = {99, 10, 120, 100, 60};
    int head = 50;
    int movement = 0;

    for (int val: requests) {
        movement += abs(head - val);
        head = val;
    }   

    cout << "Total head movement is: " << movement;
}