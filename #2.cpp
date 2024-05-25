#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct result {
    int firstElem;
    int secondElem;
};

result sumSearch(vector<int> arr, int number) {
    result out;
    for (int firstElIdx = 0; firstElIdx < arr.size(); firstElIdx++) {
        for (int secondElIdx = 0; secondElIdx < arr.size(); secondElIdx++) {
            if (arr[firstElIdx] + arr[secondElIdx] == number) {
                out.firstElem = arr[firstElIdx];
                out.secondElem = arr[secondElIdx];
                return out;
            }
        }
    }
    return out;
}


int main() {
    vector<int> a = {2, 7, 11, 15};
    result res = sumSearch(a, 9);
    cout << "first element: " << res.firstElem << "\n";
    cout << "second element: " << res.secondElem << "\n";
    return 0;
}
