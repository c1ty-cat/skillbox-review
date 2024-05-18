#include <iostream>

using namespace std;

bool checkMatrices(int firstMatrix[4][4], int secondMatrix[4][4]) {
    bool result = true;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (firstMatrix[row][col] != secondMatrix[row][col]) {
                return result = false;
            }
        }
    }
    return result;
}

void fillArr(int idx, int array[4][4]) {
    cout << "Please, enter the " << idx << " matrix:";
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int el = 0;
            cin >> el;
            array[row][col] = el;
        }
    }
}

void makeDiagonal(int array[4][4]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (!(row == col)) array[row][col] = 0;
        }
    }
}

void printArr(int (array[4][4])) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            cout << array[row][col] << " ";
        }
        cout << "\n";
    }
}


int main() {
    int firstMatrix[4][4] = {{0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0,}};
    int secondMatrix[4][4] = {{0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0}};
    fillArr(1, firstMatrix);
    fillArr(2, secondMatrix);
    bool isEqual = checkMatrices(firstMatrix, secondMatrix);
    if (isEqual) {
        makeDiagonal(firstMatrix);
        cout << "Here is your new diagonal matrix:" << "\n";
        printArr(firstMatrix);
    } else {
        cout << "Matrices are not equal!";
    }
    return 0;
}
