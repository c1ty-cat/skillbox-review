#include <iostream>
using namespace std;

void bubbleSort(double* l, double* r) {
    int sz = r - l;
    if (sz <= 1) return;
    bool b = true;
    while (b) {
        b = false;
        for (double* i = l; i + 1 < r; i++) {
            if (*i < *(i + 1)) {
                swap(*i, *(i + 1));
                b = true;
            }
        }
        r--;
    }
}

int main() {
    double arr[15];
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        cout << "Please, give the element # " << i+1 << ": ";
        cin >> arr[i];
    }
    bubbleSort(&arr[0], &arr[size]);
    cout << "Here's your sorted array: " << "\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
