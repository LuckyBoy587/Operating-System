#include <bits/stdc++.h>
using namespace std;

int main() {
    const int NUM_PHILOSOPHERS = 5;
    vector<bool> forks(NUM_PHILOSOPHERS, false);

    for (int id = 0; id < NUM_PHILOSOPHERS; id++) {
        int leftFork = id;
        int rightFork = (id + 1) % NUM_PHILOSOPHERS;

        while (forks[leftFork]) printf("Philosopher %d is waiting for left fork.\n", id + 1);
        forks[leftFork] = true;
        printf("Philosopher %d accquired the left fork.\n", id + 1);
        
        while (forks[rightFork]) printf("Philosopher %d is waiting for right fork.\n", id + 1);
        forks[rightFork] = true;
        printf("Philosopher %d accquired the right fork.\n", id + 1);

        printf("Philosopher %d is eating.\n", id + 1);
        printf("Philosopher %d has finished eating.\n", id + 1);
        cout << endl;

        forks[leftFork] = false;
        forks[rightFork] = false;
    }
}