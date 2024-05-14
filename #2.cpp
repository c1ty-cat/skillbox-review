#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
    std::vector<int> items {1, 1, 0, 3};
    float sum = 0;
    for(int i = 0; i < items.size(); i++) {
        assert(prices.size() >= items[i]);
        sum+= prices[items[i]];
    }
    cout << "Your total sum is: " << sum;
    return 0;
}
