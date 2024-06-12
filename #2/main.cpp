#include <iostream>
#include "fstream"
#include "cassert"

int main() {
    std::ifstream file;
    std::string input;
    std::cout << "Please, enter a file path: " << "\n";
    std::cin >> input;
    file.open(input, std::ios::binary); //../words.txt
    assert(file.is_open());

    std::string textLine;
    while (std::getline(file, textLine)) {
        std::cout << textLine << std::endl;
    }
    file.close();
    return 0;
}
