#include <iostream>
#include "cstring"

using namespace std;

void printResult(bool result) {
    cout << (result ? "true" : "false") << "\n";
}

bool isSubstr(const char *stringHead, const char *substringHead) {
    int i = 0;
    bool result = false;
    while (*(stringHead + i) != '\0') {
        if (*(stringHead + i) == *substringHead) {
            result = true;
            for (int k = 0; k < strlen(substringHead) - 1; ++k) {
                if (*(stringHead + i + k) != *(substringHead + k)) {
                    result = false;
                    break;
                }
            }
        }
        ++i;
    }
    return result;
}

int main() {
    bool result = false;
    const char *a = "Hello world";
    const char *b = "wor";
    const char *c = "banana";
    printResult(isSubstr(a, b));
    printResult(isSubstr(a, c));
}
