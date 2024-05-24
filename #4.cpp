#include <iostream>
#include <vector>

using namespace std;

struct element {
    bool isNegative;
    int value;
};

void printVector(vector<element> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].isNegative == true) {
            cout << "-" << vec[i].value << " ";
        } else {
            cout << vec[i].value << " ";
        }
    }
}

void bubbleSort(vector<element> &vec) {
    for (int i = 0; i < vec.size()-1; i++) {
        for (int j = 0; j < vec.size()-1; j++) {
            if (vec[j].value > vec[j + 1].value) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void getStructArray(vector<int> &initialVec, vector<element> &resultVec) {
    for(int i = 0; i < initialVec.size(); i++) {
        if(initialVec[i] < 0) {
            resultVec[i].isNegative = true;
        } else {
            resultVec[i].isNegative = false;
        }
        resultVec[i].value = abs(initialVec[i]);
    }
}


int main() {
    vector<int> initialVec = {-100, -50, -5, 1, 10, 15};
    vector<element> resultVec(initialVec.size());
    getStructArray(initialVec, resultVec);
    bubbleSort(resultVec);
    printVector(resultVec);
    return 0;
}
