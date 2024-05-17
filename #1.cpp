#include <iostream>

int main() {
    int utensils[2][6] = {{4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3}};
    int plates[2][6] = {{3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2}};
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

    // Lady with a kid needs a chair
    chairs[0][4] += 1;
    // Someone stole a spoon
    utensils[1][2] -= 1;
    // Vip member gave away his spoon to that person
    utensils[0][0] -= 1;
    utensils[1][2] += 1;
    // Vip member's desert plate was taken by a waiter
    plates[0][0] -= 1;
    return 0;
}
