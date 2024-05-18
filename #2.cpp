#include <iostream>

using namespace std;

struct result {
    int code, row, col;
};

bool checkWinner(int field[3][3], int playerCode) {
    bool isWinner = false;
    // check horizontal
    for (int row = 0; row < 3; row++) {
        int magicSum = 0;
        for (int col = 0; col < 3; col++) {
            if (field[row][col] == playerCode) {
                magicSum += 1;
            }
        }
        if (magicSum == 3) {
            isWinner = true;
            break;
        }
    }
    if (isWinner) return isWinner;
    // check vertical
    for (int row = 0; row < 3; row++) {
        int magicSum = 0;
        for (int col = 0; col < 3; col++) {
            if (field[col][row] == playerCode) {
                magicSum += 1;
            }
        }
        if (magicSum == 3) {
            isWinner = true;
            break;
        }
    }
    if (isWinner) return isWinner;
    // check main diagonal
    int magicSum = 0;
    for (int row = 0; row < 3; row++) {
        if (field[row][row] == playerCode) {
            magicSum += 1;
        }
        if (magicSum == 3) {
            isWinner = true;
            break;
        }
    }
    if (isWinner) return isWinner;
    // check reverse diagonal
    magicSum = 0;
    for (int row = 0; row < 3; row++) {
        if (field[row][2-row] == playerCode) {
            magicSum += 1;
        }
        if (magicSum == 3) {
            isWinner = true;
            break;
        }
    }
    return isWinner;
}

void printField(int field[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (field[row][col] == 0) cout << "- ";
            else if (field[row][col] == 1) cout << "X ";
            else cout << "O ";
        }
        cout << "\n";
    }
}

result getInput(int playerIdx, int field[3][3]) {
    int playerCode = playerIdx;
    int inputRow;
    int inputCol;
    bool badFlag = false;
    do {
        badFlag = false;
        cout << "Player #" << playerIdx << " , enter row(0 - 2): ";
        cin >> inputRow;
        cout << "Player #" << playerIdx << " , enter col(0 - 2): ";
        cin >> inputCol;
        if (!(inputRow <= 2 && inputRow >= 0)) badFlag = true;
        else if (!(inputCol <= 2 && inputCol >= 0)) badFlag = true;
        else if (field[inputRow][inputCol] != 0) badFlag = true;
        if (badFlag) cout << "Wrong input or the specified position is occupied! Try again" << "\n";
    } while (badFlag);
    return result{playerCode, inputRow, inputCol};
}

int main() {
    // 0 - '', 1 - X, 2 - O
    int field[3][3] = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};
    printField(field);

    for (int move = 1; move < 10; move++) {
        bool isWinner = false;
        int playerIdx = (move + 1) % 2 == 0 ? 1 : 2;
        result output = getInput(playerIdx, field);
        field[output.row][output.col] = output.code;
        printField(field);
        isWinner = checkWinner(field, playerIdx);
        if (isWinner) {
            cout << "Player #" << playerIdx << " , you've won!";
            return 0;
        }
    }
    cout << "It's a draw! Game over";
    return 0;
}
