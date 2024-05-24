#include <iostream>
#include <limits>
# include <vector>

using namespace std;

    // Подсмотрел решение с эффективным алгоритмом,
    // на его основе сделал вывод индексов

    struct result {
        int sum; int firstIdx; int lastIdx;
    };


result maximumSumSubarray(vector<int> arr, int n)
{
    result out;
    // Initialize minimum prefix sum to 0.
    int min_prefix_sum = 0;

    // Initialize maximum subarray sum so
    // far to -infinity.
    int res = numeric_limits<int>::min();

    // Initialize and compute the prefix
    // sum array.
    vector<int> prefix_sum(n);
    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];

    // loop through the array, keep track
    // of minimum prefix sum so far and
    // maximum subarray sum.
    int startIdx = 0;
    int endIdx = 0;
    int oldRes = 0;
    int oldMin = 0;
    for (int i = 0; i < n; i++) {
        oldRes = res;
        oldMin = min_prefix_sum;
        res = max(res, prefix_sum[i] - min_prefix_sum);
        if(oldRes != res) endIdx = i;
        if(res > (prefix_sum[i] - min_prefix_sum))
        min_prefix_sum = min(min_prefix_sum, prefix_sum[i]);
        if(oldMin != min_prefix_sum) startIdx = i+1;
    }

    out.lastIdx = endIdx;
    out.firstIdx = startIdx;
    out.sum = res;

    return out;
}


int main() {
    vector<int> a = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};
    cout << "first IDX: " << maximumSumSubarray(a, a.size()).firstIdx << "\n";
    cout << "last IDX: " << maximumSumSubarray(a, a.size()).lastIdx << "\n";
    cout << "sum " << maximumSumSubarray(a, a.size()).sum << "\n";
    return 0;
}
