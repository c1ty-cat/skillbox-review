#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapArr(int *head, int *tail) {
    while (head < tail) {
        swap(head, tail);
        head++;
        tail--;
    }
}

void print(int *el, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(el + i) << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    print(arr, len);
    swapArr(arr, arr + len-1);
    print(arr, len);
}
