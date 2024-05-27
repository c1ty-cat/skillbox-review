#include <iostream>

using namespace std;

void printCurrentSpeed(float speed_value) {
    char speed_str[10];
    sprintf(speed_str, "%.1f", speed_value);
    cout << "Speed: " << speed_str << "\n";
}

bool isRelativelyEqual(float lhs, float rhs, float epsilon = 0.01) {
    return abs(lhs - rhs) < epsilon;
}

bool isProgramEnd(float speed_value) {
    bool isDone = false;
    if (isRelativelyEqual(speed_value, 0.0)) isDone = true;
    else if (isRelativelyEqual(150.0, speed_value)) isDone = true;
    else if(speed_value < 0.0 || speed_value > 150.0) isDone = true;
    return isDone;
}

int main() {
    float current_speed = 0;
    float speed_delta = 0;
    do {
        cout << "Speed delta: ";
        cin >> speed_delta;
        current_speed += speed_delta;
        printCurrentSpeed(current_speed);
    } while (!isProgramEnd(current_speed));
    return 0;
}
