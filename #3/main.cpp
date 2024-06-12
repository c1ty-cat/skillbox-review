#include <iostream>
#include "fstream"
#include "vector"

struct client {
    std::string firstName;
    std::string lastName;
    int payout;
    std::string date;
};

int findTotal(std::vector<client> db) {
    int total = 0;
    for (int i = 0; i < db.size(); ++i) {
        total += db[i].payout;
    }
    return total;
}

int findMaxPayoutIdx(std::vector<client> db) {
    int maxIdx = 0;
    for (int i = 0; i < db.size(); ++i) {
        if (db[i].payout > db[maxIdx].payout) maxIdx = i;
    }
    return maxIdx;
}


int main() {
    std::vector<client> container;
    std::ifstream dataBase;
    dataBase.open("../list.txt");
    while (!dataBase.eof()) {
        client person;
        dataBase >> person.firstName >> person.lastName;
        dataBase >> person.payout;
        dataBase >> person.date;
        container.push_back(person);
    }
    for (int i = 0; i < container.size(); ++i) {
        std::cout << container[i].firstName << " " << container[i].lastName << " ";
        std::cout << container[i].payout << " " << container[i].date << "\n";
    }
    std::cout << "\n" << "---------------------REPORT------------------------- " << "\n";
    std::cout << "Total amount of payout: " << findTotal(container) << "\n";
    int maxIdx = findMaxPayoutIdx(container);
    std::cout << "The highest payout belongs to: "
              << container[maxIdx].firstName << " " << container[maxIdx].lastName << "\n";
    std::cout << "The transaction was completed on " << container[maxIdx].date << "\n";
    std::cout << "The payout amount is " << container[maxIdx].payout;
    return 0;
}
