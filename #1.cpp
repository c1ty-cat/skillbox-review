#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;


void printVector(const vector<int>& vec,string sep = " ")
{
    for (auto elem : vec) {
        cout << elem << sep;
    }
    cout << endl;
}


vector<int> getVector(int size) {
    vector<int> numbers;
    int counter = 0;
    int num;
    while (counter < size) {
        cout << "Please, give a number #" << counter + 1 << " ";
        cin >> num;
        assert(num > 0 && num < 9);
        numbers.push_back(num);
        counter++;
    }
    cout << "Here's the vector that you entered: ";
    printVector(numbers);
    return numbers;
}

int main() {
    int size;
    vector<int> v;
    int badElement;

    cout << "Please, give the vector's size: ";
    cin >> size;
    v = getVector(size);
    cout << "Now declare a number that you'd like to remove from the vector:  ";
    cin >> badElement;
    for(int i = 0; i < v.size();) {
        if (v[i] == badElement) {
            v.erase(v.begin() + i);
        }
        else i++;
    }
    cout << "Here's your new vector: ";
    printVector(v);
    return 0;
}
