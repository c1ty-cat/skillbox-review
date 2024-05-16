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

vector<int> pushElement(vector<int> &vec, int headIdx, int tailIdx, int el) {
    if(tailIdx < vec.size()) {
        vec[tailIdx] = el;
    } else {
        vec.erase(vec.begin());
        vec.push_back(el);
    }
    return vec;
}

int main() {
    int vecSize = 20;
    vector<int> db(vecSize);
    int input;
    int headIdx = 0;
    int tailIdx = 0;
    while (true) {
        cout << "COMMANDS: '-1' to print the database, '0' to quit " << "\n";
        cout << "Declare a number for the storage: ";
        cin >> input;
        if (input == -1) printVector(db);
        else if (input == 0) {
            cout << "Quitting the program" << "\n";
            printVector(db);
            break;
        } else {
            db = pushElement(db, headIdx, tailIdx, input);
            tailIdx == vecSize ? : tailIdx++;
        }

    }
    return 0;
}
