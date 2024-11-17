#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> files;

void createDirectory() {
    string directory;
    cin >> directory;
    files[directory] = vector<string>();
}

void createFile() {
    string directory, fileName;
    cin >> directory >> fileName;
    files[directory].push_back(fileName);
}

void deleteFile() {
    string directory, fileName;
    cin >> directory >> fileName;
    files[directory].erase(find(files[directory].begin(), files[directory].end(), fileName));
}

void searchFile() {
    string directory, fileName;
    cin >> directory >> fileName;
    if (find(files[directory].begin(), files[directory].end(), fileName) != files[directory].end()) {
        cout << "File is present";
    } else {
        cout << "File is not present";
    }
    cout << endl;
}

void displayFiles() {
    cout << "Files are: \n";
    cout << "Directory\t\t\tFiles\n";
    for (auto& pair: files) {
        for (string& fileName: pair.second) {
            cout << pair.first << ' ' << fileName << endl;
        }
    }
    cout << endl;
}

int main() {
    while (true) {
        cout << "1. Create Directory\n";
        cout << "2. Create File\n";
        cout << "3. Delete File\n";
        cout << "4. Search File\n";
        cout << "5. Display Files\n";
        cout << "6. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            createDirectory();
        } else if (choice == 2) {
            createFile();
        } else if (choice == 3) {
            deleteFile();
        } else if (choice == 4) {
            searchFile();
        } else if (choice == 5) {
            displayFiles();
        } else {
            break;
        }
    }
}