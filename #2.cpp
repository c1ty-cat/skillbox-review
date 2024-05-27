#include <iostream>
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

double concatenate(string leftValue, string rightValue) {
    return stod(leftValue + "." + rightValue);
}

bool is_digits(string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

int main() {
    string leftVal = "";
    string rightVal = "";
    cout << "Please, give the left part of the number: ";
    cin >> leftVal;
    assert(is_digits(leftVal));
    cout << "Please, give the right part of the number: ";
    cin >> rightVal;
    assert(is_digits(rightVal));
    cout << "Your new double value is: " << concatenate(leftVal, rightVal);
    return 0;
}
