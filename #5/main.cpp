#include <iostream>
#include "fstream"
#include "vector"

struct sector {
    int num;
    bool wasPlayed;
    std::string sectorName;
    std::string answerName;
};

sector getSector(int offset, std::vector<sector> db) {
    if (db[offset].wasPlayed) {
        for (int i = 1; i <= 13; ++i) {
            if (offset + i > 13) offset -= 13;
            if (db[offset + i].wasPlayed == false) {
                return db[offset + i];
            };
        }
    } else return db[offset];
}


int main() {
    std::vector<sector> db(13);
    for (int i = 0; i < 13; i++) {
        db[i].wasPlayed = false;
        db[i].num = i;
        db[i].sectorName = "sector_" + std::to_string(i + 1);
        db[i].answerName = "answer_" + std::to_string(i + 1);
    }

    int playerScore = 0;
    int viewersScore = 0;
    while (playerScore < 6 && viewersScore < 6) {
        std::cout << "------------------------------------" << "\n";
        // Getting the offset
        int offset = 0;
        std::cout << "Please, enter the offset (taken from sector #1): ";
        std::cin >> offset;
        sector currSector = getSector(offset, db);
        std::ifstream currQuestion;
        std::ifstream currAnswer;
        // Asking a question
        currQuestion.open("../" + currSector.sectorName + ".txt");
        std::string questionText;
        std::getline(currQuestion, questionText);
        std::cout << "Your question is: " << questionText << "\n";
        db[currSector.num].wasPlayed = true;
        // Getting an answer
        currAnswer.open("../" + currSector.answerName + ".txt");
        std::cout << "Your answer: ";
        std::string answerText;
        std::getline(currAnswer, answerText);
        std::string userAnswer;
        std::cin >> userAnswer;
        // Comparing
        if (userAnswer == answerText) playerScore++;
        else viewersScore++;
        currQuestion.close();
        currAnswer.close();
        std::cout << "Player score: " << playerScore;
        std::cout << " Viewers score: " << viewersScore << "\n";
    }
    std::cout << "-------------GAME-RESULTS--------------" << "\n";
    std::cout << (playerScore == 6 ? "Players won!" : "Viewers won!") << "\n";
    return 0;
}
