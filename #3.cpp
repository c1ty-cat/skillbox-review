#include <iostream>
#include "vector"

using namespace std;

void bubbleSort(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void printVector(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

void pushEl(vector<int> &vec, int el, int counter) {
    if (counter <= 4) {
        vec[counter] = el;
    } else {
        if (vec[counter] > el) {
            vec[counter] = el;
        }
    }
    if (counter >= 4) bubbleSort(vec);
}

int main() {
    vector<int> vec(5);
    int input;
    int counter = 0;
    while (true) {
        cout << "Please, enter a value or a command: ";
        cin >> input;
        if (input == -1) {
            if (counter < 5) {
                cout << "input at least 5 numbers" << "\n";
            } else {
                printVector(vec);
                cout << "\n";
                cout << "Your element is " << vec[4] << "\n";
            }
        } else if (input == -2) {
            cout << "Quitting the program";
            return 0;
        } else {
            pushEl(vec, input, counter);
            if (counter < 5) counter++;
        }
    }
}
