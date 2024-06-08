#include <iostream>

void evenDigits(long long int num, int& ans) {
    std::string numStr = std::to_string(num);
    if (numStr.length() == 0) return;
    else {
        int currDigit = numStr[numStr.length() - 1] - '0';
        if (currDigit % 2 == 0) ++ans;
        numStr.pop_back();
        if (numStr.length() == 0) return;
        char* endPtr = NULL;
        const char* begPtr = numStr.c_str();
        evenDigits(std::strtoll(begPtr, &endPtr, 10), ans);
    }
}

int main() {
    long long num = 9223372036854775806;
    int ans = 0;
    evenDigits(num, ans);
    std::cout << ans;
    return 0;
}
