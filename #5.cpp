#include <iostream>
#include <cassert>
using namespace std;


void fillPop(bool array[12][12]) {
    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < 12; col++) {
            array[row][col] = true;
        }
    }
}

void getTask(int popArray[2][2]) {
    cout << "Give the coordinates lying between [0][0] - top left corner of\n";
    cout << "the field and [11][11] - bottom right corner of the field\n\n";
    cout << "Give the 'X' (column) of the top left corner: ";
    cin >> popArray[0][1];
    assert(popArray[0][1] >= 0 && popArray[0][1] <= 11);
    cout << "Give the 'Y' (row) of the top left corner: ";
    cin >> popArray[0][0];
    assert(popArray[0][0] >= 0 && popArray[0][0] <= 11);
    cout << "Give the 'X' (column) of the bottom right corner: ";
    cin >> popArray[1][1];
    assert(popArray[1][1] >= 0 && popArray[1][1] <= 11);
    cout << "Give the 'Y' (row) of the bottom right corner: ";
    cin >> popArray[1][0];
    assert(popArray[1][0] >= 0 && popArray[1][0] <= 11);
    cout << "\n";
}

void pop(bool popArray[12][12], int popRegion[2][2]) {

    int topCornerX = 0;
    int topCornerY = 0;
    int bottomCornerX = 0;
    int bottomCornerY = 0;

    // Organising the received coordinates
    if (popRegion[0][0] < popRegion[1][0]) {
        topCornerY = popRegion[0][0];
        bottomCornerY = popRegion[1][0];
    } else {
        topCornerY = popRegion[1][0];
        bottomCornerY = popRegion[0][0];
    }
    if (popRegion[0][1] < popRegion[1][1]) {
        topCornerX = popRegion[0][1];
        bottomCornerX = popRegion[1][1];
    } else {
        topCornerX = popRegion[1][1];
        bottomCornerX = popRegion[0][1];
    }

    for (int row = topCornerY; row <= bottomCornerY; row++) {
        for (int col = topCornerX; col <= bottomCornerX; col++) {
            if(popArray[row][col] == true) {
                cout << "Pop! ";
                popArray[row][col] = false;
            }
        }
    }
    cout << "\n";
}

bool printPop(bool array[12][12]) {
    bool isPopped = true;
    cout << "\n";
    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < 12; col++) {
            if(array[row][col] == true){
                cout << "o ";
                isPopped = false;
            }
            else cout << "x ";
        }
        cout << "\n";
    }
    cout << "\n";
    return isPopped;
}


int main() {
    bool popTemplate[12][12];
    int taskTemplate[2][2];
    bool popped = false;
    fillPop(popTemplate);
    do {
        getTask(taskTemplate);
        pop(popTemplate, taskTemplate);
        popped = printPop(popTemplate);
    } while(!popped);
    cout << "Everything is popped!";
    return 0;
}
