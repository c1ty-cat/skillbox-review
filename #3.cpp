#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

struct input {
    double leftVal;
    char action;
    double rightVal;
};


bool checkAction(char action) {
    bool isOK = false;
    if (action == '+') isOK = true;
    else if (action == '-') isOK = true;
    else if (action == '/') isOK = true;
    else if (action == '*') isOK = true;
    return isOK;
}

double calculate(double leftValue, double rightValue, char action) {
    double result = 0;
    switch (action) {
        case '+' :
            result = leftValue + rightValue;
            break;
        case '-' :
            result = leftValue - rightValue;
            break;
        case '/' :
            result = leftValue / rightValue;
            break;
        case '*' :
            result = leftValue * rightValue;
            break;
    }
    return result;
}

input getInput() {
    string inputStr = "";
    cout << "Enter an expression: ";
    cin >> inputStr;
    input output;
    double leftVal;
    double rightVal;
    char action;
    input input;
    stringstream buffer_stream(inputStr);
    buffer_stream >> leftVal >> action >> rightVal;
    assert(checkAction(action));
    output.leftVal = leftVal;
    output.action = action;
    output.rightVal = rightVal;
    return output;
}

int main() {
    input data = getInput();
    double result = calculate(data.leftVal, data.rightVal, data.action);
    cout << data.leftVal << data.action << data.rightVal << "=" << result;
    return 0;
}
