#include <iostream>

using namespace std;


void fillArr(int array[4][4]) {
    cout << "Please, enter the matrix elements:" << "\n";
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int el = 0;
            cin >> el;
            array[row][col] = el;
        }
    }
}

void fillVector(int array[4]) {
    cout << "Please, enter the vector elements:" << "\n";
    for (int col = 0; col < 4; col++) {
        int el = 0;
        cin >> el;
        array[col] = el;
    }

}

void calculateResult(int resultArr[4], int matrix[4][4], int vector[4]) {
    for (int row = 0; row < 4; row++) {
        int rowAccumulator = 0;
        for (int col = 0; col < 4; col++) {
            rowAccumulator += matrix[row][col] * vector[row];
        }
        resultArr[row] = rowAccumulator;
    }
}

void printResult(int array[4]) {
    cout << "Your result vector is:" << "\n";
    for (int col = 0; col < 4; col++) {
        cout << "|" << array[col] << "|" << "\n";
    }
}


int main() {
    int matrixTemplate[4][4] = {{1, 2, 3, 4},
                                {0, 0, 0, 0},
                                {4, 4, 4, 4},
                                {0, 0, 0, 0}};
    int vectorTemplate[4] = {1, 0, 2, 0};
    int resultTemplate[4] = {0, 0, 0, 0};

    fillArr(matrixTemplate);
    fillVector(vectorTemplate);
    calculateResult(resultTemplate, matrixTemplate, vectorTemplate);
    printResult(resultTemplate);
    return 0;
}
