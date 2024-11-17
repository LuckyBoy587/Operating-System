#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> pageReferences = {1, 2, 3, 4, 3, 2, 1, 1, 4, 3};
    const int FRAME_COUNT = 3;
    int pageFault = 0;

    vector<int> pageTable;

    for (int i = 0; i < pageReferences.size(); i++) {
        int page = pageReferences[i];

        if (find(pageTable.begin(), pageTable.end(), page) == pageTable.end()) {
            pageFault++;
            if (pageTable.size() == FRAME_COUNT) {
                int deletePage = -1;
                int maxDistance = -1;

                for (int storedPage : pageTable) {
                    auto it = find(pageReferences.begin() + i + 1, pageReferences.end(), storedPage);
                    int dist = distance(pageReferences.begin(), it);
                    
                    if (dist > maxDistance) {
                        maxDistance = dist;
                        deletePage = storedPage;
                    }
                }

                pageTable.erase(find(pageTable.begin(), pageTable.end(), deletePage));
            }
            pageTable.push_back(page);
        }
    }

    cout << "Number of page faults: " << pageFault << endl;
}