#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int getMask(char noteIdx) {
    int mask = 0;
    switch (noteIdx) {
        case '1':
            mask |= note::DO;
            break;
        case '2':
            mask |= note::RE;
            break;
        case '3':
            mask |= note::MI;
            break;
        case '4':
            mask |= note::FA;
            break;
        case '5':
            mask |= note::SOL;
            break;
        case '6':
            mask |= note::LA;
            break;
        case '7':
            mask |= note::SI;
            break;
    }
    return mask;
}

void printNotes(int notes) {
    if (notes & DO) std::cout << "DO";
    if (notes & RE) std::cout << "RE";
    if (notes & MI) std::cout << "MI";
    if (notes & FA) std::cout << "FA";
    if (notes & SOL) std::cout << "SOL";
    if (notes & LA) std::cout << "LA";
    if (notes & SI) std::cout << "SI";
}

int main() {
    string input = "";
    cout << "enter notes: ";
    cin >> input;
    int notes = 0;
    for (int i = 0; i < input.length(); ++i) {
        notes |= getMask(char(input[i]));
    }
    printNotes(notes);
    return 0;
}
