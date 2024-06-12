#include <iostream>
#include "fstream"
#include "vector"

int check(std::string word, std::vector<std::string> container) {
    int counter;
    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == word) ++counter;
    }
    return counter;
}

int main() {
    std::vector<std::string> container;
    std::ifstream words;
    words.open("../words.txt");
    int count = 0;
    while (!words.eof()) {
        std::string word;
        words >> word;
        container.push_back(word);
    }
    for (int i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::string input;
    std::cout << "Please, enter a word for search: " << "\n";
    std::cin >> input;
    std::cout << check(input, container);
    return 0;
}
