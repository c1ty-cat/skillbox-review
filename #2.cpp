#include <iostream>


int calcJumpOptions(int n, int i = 3, int k = 3) {
    if (n == 0) {
        return 1;
    } else {
        if (n < 0 || i < 1) {
            return 0;
        } else {
            return calcJumpOptions(n - i, k, k) + calcJumpOptions(n, i - 1, k);
        }
    }
}

int main() {
    int n = 7;
    int k = 2;
    /*std::cin >> n;
    std::cin >> k;*/
    std::cout << calcJumpOptions(n, k, k);
}

