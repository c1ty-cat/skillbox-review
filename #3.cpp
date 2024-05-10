#include <iostream>
#include <cassert>

using namespace std;

using namespace std;

float travelTime(float distance, float speed) {
    assert(speed > 0);
    return distance / speed;
}

int main() {
    float distance, speed;
    cout << "Please, enter distance (in meters): ";
    cin >> distance;
    cout << "Please, enter speed (in m/s): ";
    cin >> speed;
    cout << "Your average travel time is " << travelTime(distance, speed) << " sec.";
    return 0;
}