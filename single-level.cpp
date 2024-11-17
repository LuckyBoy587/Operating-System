#include <bits/stdc++.h>
using namespace std;

vector<string> files;

void createFile() {
    string fileName;
    cin >> fileName;
    files.push_back(fileName);
}

void deleteFile() {
    string fileName;
    cin >> fileName;
    files.erase(find(files.begin(), files.end(), fileName));
}

void searchFile() {
    string fileName;
    cin >> fileName;
    if (find(files.begin(), files.end(), fileName) != files.end()) {
        cout << "File is present";
    } else {
        cout << "File is not present";
    }
    cout << endl;
}

void displayFiles() {
    cout << "Files in the directory are: \n";
    for (string &fileName : files) {
        cout << fileName << endl;
    }
}

int main() {
    while (true) {
        cout << "1. Create File\n";
        cout << "2. Delete File\n";
        cout << "3. Search File\n";
        cout << "4. Display Files\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            createFile();
        } else if (choice == 2) {
            deleteFile();
        } else if (choice == 3) {
            searchFile();
        } else if (choice == 4) {
            displayFiles();
        } else {
            break;
        }
    }
}