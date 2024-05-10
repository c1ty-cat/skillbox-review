#include <iostream>
using namespace std;

void bubbleSort(int* l, int* r) {
    int sz = r - l;
    if (sz <= 1) return;
    bool b = true;
    while (b) {
        b = false;
        for (int* i = l; i + 1 < r; i++) {
            if (*i < *(i + 1)) {
                swap(*i, *(i + 1));
                b = true;
            }
        }
        r--;
    }
}

int findClone (int arr[], int size) {
    int counter = 0;
    int clone = 0;
    while (counter < size - 1) {
        if (arr[counter] == arr[counter + 1]) {
            clone = arr[counter];
            break;
        }
        counter++;
    }
    return clone;
}

int main() {
    int arr[15] = {104, 107, 103, 102, 101, 105, 101, 106, 109, 108, 111, 110, 113, 112, 114};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(&arr[0], &arr[size]);
    cout << "Here's your clone: " << findClone(arr, size) << "\n";
    return 0;
}
