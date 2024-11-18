#include <iostream>
#include <vector>
using namespace std;

bool isNeedLessThanWork(vector<int> &need, vector<int> &work) {
    for (int i = 0; i < need.size(); i++) {
        if (need[i] > work[i])
            return false;
    }

    return true;
}

int main() {
    int processCount, resourceCount;
    cin >> processCount >> resourceCount;
    vector<vector<int>> allocation(processCount, vector<int>(resourceCount));
    vector<vector<int>> maxRequired(processCount, vector<int>(resourceCount));
    vector<int> work(resourceCount);
    vector<vector<int>> needMatrix(processCount, vector<int>(resourceCount));

    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < resourceCount; j++) {
            cin >> allocation[i][j];
        }
    }

    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < resourceCount; j++) {
            cin >> maxRequired[i][j];
            needMatrix[i][j] = maxRequired[i][j] - allocation[i][j];
        }
    }

    for (int i = 0; i < resourceCount; i++) {
        cin >> work[i];
    }

    int completedCount = 0;
    bool completed[processCount];
    while (completedCount < processCount) {
        bool flag = false;
        for (int i = 0; i < processCount; i++) {
            if (!completed[i] && isNeedLessThanWork(needMatrix[i], work)) {
                for (int j = 0; j < resourceCount; j++)
                    work[j] += allocation[i][j];
                completed[i] = true;
                flag = true;
                completedCount++;
            }
        }

        if (!flag) {
            cout << "System is not Safe";
            return 0;
        }
    }
    cout << "System is Safe";
}