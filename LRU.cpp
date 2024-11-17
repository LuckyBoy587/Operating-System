#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> pageReferences = {7, 5, 9, 4, 3, 7, 9, 6, 2, 1};
    const int FRAME_COUNT = 4;
    int pageFault = 0;
    map<int, int> pageTable;

    for (int i = 0; i < pageReferences.size(); i++) {
        int page = pageReferences[i];
        if (pageTable.find(page) == pageTable.end()) {
            pageFault++;
            if (pageTable.size() == FRAME_COUNT) {
                int lruPage = -1, lruIndex = i;
                for (auto &pair : pageTable) {
                    if (pair.second < lruIndex) {
                        lruIndex = pair.second;
                        lruPage = pair.first;
                    }
                }
                pageTable.erase(pageTable.find(lruPage));
            }
            pageTable.insert({page, i});
        }
    }

    cout << "Page Fault: " << pageFault;
}