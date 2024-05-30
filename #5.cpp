#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

struct home_state {
    int switches_state;
    double lightTemp;
    int currentHour;
};

enum switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16,
};

double setLightTemp(int time) {
    double lightTemp = 0;
    if (time > 16 && time <= 20) {
        lightTemp = 5000 - (5000 - 2700) / (20 - 16) * (time - 16);
    } else if (time > 20 && time < 24) {
        lightTemp = 2700;
    } else if (time >= 24 && time < 16 + 24) {
        lightTemp = 5000;
    } else if (time > 16 + 24 && time < 20 + 24) {
        lightTemp = 5000 - (5000 - 2700) / (20 - 16) * (time - 16 - 24);
    } else if (time > 20 + 24) {
        lightTemp = 2700;
    }
    return lightTemp;
}

home_state setState(int time) {
    string tempIns;
    string tempOut;
    string movement;
    string lights;
    string input;
    home_state state;
    state.switches_state = 0;
    state.currentHour = time;
    cout << "Temperature inside, temperature outside, movement, lights: ";
    getline(cin, input);
    stringstream buffer_stream(input);
    buffer_stream >> tempIns >> tempOut >> movement >> lights;
    // PIPE HEATING
    if (stoi(tempOut) < 0) state.switches_state |= WATER_PIPE_HEATING;
    else if (stoi(tempOut) > 5) state.switches_state &= ~WATER_PIPE_HEATING;
    // LIGHTS OUTSIDE
    if ((time > 16 && time < 29 || time > 16 + 24) && movement == "yes") state.switches_state |= LIGHTS_OUTSIDE;
    else state.switches_state &= ~LIGHTS_OUTSIDE;
    // HEATERS
    if (stoi(tempIns) < 22) state.switches_state |= HEATERS;
    else if (stoi(tempIns) >= 25) state.switches_state &= ~HEATERS;
    // CONDITIONER
    if (stoi(tempIns) >= 30) state.switches_state |= CONDITIONER;
    else if (stoi(tempIns) <= 25) state.switches_state &= ~CONDITIONER;
    // LIGHTS
    if (lights == "on") {
        state.switches_state |= LIGHTS_INSIDE;
        state.lightTemp = setLightTemp(time);
    } else state.switches_state &= ~LIGHTS_INSIDE;
    return state;
}

void printState(home_state oldState, home_state newState) {
    if (!(oldState.switches_state & LIGHTS_INSIDE)
        && (newState.switches_state & LIGHTS_INSIDE)) {
        cout << "Lights inside ON!" << "\n";
    } else if ((oldState.switches_state & LIGHTS_INSIDE)
               && !(newState.switches_state & LIGHTS_INSIDE))
        cout << "Lights inside OFF!" << "\n";
    if (newState.switches_state & LIGHTS_INSIDE)
        cout << "Color temperature: " << newState.lightTemp << "K\n";
    if (!(oldState.switches_state & LIGHTS_OUTSIDE)
        && (newState.switches_state & LIGHTS_OUTSIDE))
        cout << "Lights outside ON!" << "\n";
    else if ((oldState.switches_state & LIGHTS_OUTSIDE)
             && !(newState.switches_state & LIGHTS_OUTSIDE))
        cout << "Lights outside OFF!" << "\n";
    if (!(oldState.switches_state & HEATERS)
        && (newState.switches_state & HEATERS))
        cout << "Heaters ON!" << "\n";
    else if ((oldState.switches_state & HEATERS)
             && !(newState.switches_state & HEATERS))
        cout << "Heaters OFF!" << "\n";
    if (!(oldState.switches_state & WATER_PIPE_HEATING)
        && (newState.switches_state & WATER_PIPE_HEATING))
        cout << "Pipe heaters ON!" << "\n";
    else if ((oldState.switches_state & WATER_PIPE_HEATING)
             && !(newState.switches_state & WATER_PIPE_HEATING))
        cout << "Pipe heaters OFF!" << "\n";
    if (!(oldState.switches_state & CONDITIONER)
        && (newState.switches_state & CONDITIONER))
        cout << "Conditioner ON!" << "\n";
    else if ((oldState.switches_state & CONDITIONER)
             && !(newState.switches_state & CONDITIONER))
        cout << "Conditioner OFF!" << "\n";
    cout << "Hour: " << newState.currentHour << "\n";
}


int main() {
    home_state oldState;
    oldState.switches_state = 0;
    oldState.lightTemp = 0;
    for (int time = 16; time <= 48; ++time) {
        home_state newState;
        newState = setState(time);
        printState(oldState, newState);
        oldState = newState;
    }
    return 0;
}
