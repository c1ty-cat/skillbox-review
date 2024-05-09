#include <iostream>
#include<assert.h>//std::assert

using namespace std;


int main() {
    string people[10];
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        cout << "please, enter a dweller's name: ";
        cin >> people[i];
    }
    for (int i = 0; i < 3; i++) {
        cout << "please, enter an apartment's number: ";
        cin >> idx;
        assert(idx < 11 && idx > 0);
        cout << "The apartment #" << idx << " is occupied by " << people[idx - 1] << "\n";
    }

    return 0;
}
