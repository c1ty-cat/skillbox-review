#include <iostream>
#include "fstream"
#include "cassert"

bool isPNG(char buffer[4]) {
    bool result = false;
    if ((int)buffer[0] == -119 &&
        buffer[1] == 'P' &&
        buffer[2] == 'N' &&
        buffer[3] == 'G') {
        result = true;
    }
    return result;
}

int main() {
    std::ifstream file;
    std::string input;
    std::cout << "Please, enter a file path: " << "\n";
    std::cin >> input;
    file.open(input, std::ios::binary); //../cat.png
    assert(file.is_open());

    char buffer[4];
    file.read(buffer, sizeof(buffer));
    std::cout << (isPNG(buffer) ? "it is a PNG!" : "it is not a PNG");
    file.close();
    return 0;
}
