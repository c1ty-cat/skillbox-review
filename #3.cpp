#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;


void printVector(const vector<int> &vec, string sep = " ") {
    cout << "Elements in the database: ";
    for (auto elem : vec) {
        cout << elem << sep;
    }
    cout << endl;
}

int main() {
    vector<int> db;
    int input;
    while (true) {
        cout << "COMMANDS: '-1' to print the database, '0' to quit " << "\n";
        cout << "Declare a number for the storage: ";
        cin >> input;
        if (input == -1) printVector(db);
        else if (input == 0) {
            cout << "Quitting the program" << "\n";
            printVector(db);
            break;
        } else db.push_back(input);
        if(db.size() == 20) {
            cout << "Storage is full, quitting the program" << "\n";
            printVector(db);
            break;
        }
    }
    return 0;
}
