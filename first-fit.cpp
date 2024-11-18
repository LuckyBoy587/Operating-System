#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, size, allocatedBlock, blockSize, fragmentSize;
};

int main() {
    int blockCount;
    cin >> blockCount;
    vector<int> blockSize(blockCount);
    for (int i = 0; i < blockCount; i++) {
        cin >> blockSize[i];
    }

    int processCount;
    cin >> processCount;
    vector<Process> process(processCount);
    for (int i = 1; i <= processCount; i++) {
        process[i - 1].id = i;
        cin >> process[i - 1].size;
    }

    for (Process &p : process) {
        bool flag = false;
        for (int i = 0; i < blockCount; i++) {
            if (blockSize[i] >= p.size) {
                p.allocatedBlock = i + 1;
                p.blockSize = blockSize[i];
                blockSize[i] -= p.size;
                p.fragmentSize = blockSize[i];
                flag = true;
                break;
            }
        }

        if (!flag) {
            p.allocatedBlock = -1;
        }
    }

    for (Process &p : process) {
        if (p.allocatedBlock == -1) {
            printf("Process %d has to wait...\n", p.id);
        } else {
            cout << "ID: " << p.id << ", Size: " << p.size
                 << ", Allocated Block: " << p.allocatedBlock
                 << ", Block Size: " << p.blockSize
                 << ", Fragment Size: " << p.fragmentSize << endl;
        }
    }
}