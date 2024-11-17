#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> pageReferences = {4, 1, 2, 4, 5};
    int frameCount = 3;
    set<int> pageTable;
    queue<int> q;
    int pageFault = 0;

    for (int page : pageReferences) {
        if (pageTable.find(page) == pageTable.end()) {
            pageFault++;
            if (q.size() == frameCount) {
                int removePage = q.front();
                q.pop();
                pageTable.erase(pageTable.find(removePage));
            }
            pageTable.insert(page);
            q.push(page);
        }
    }

    cout << "Page Fault: " << pageFault;
}