#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;

ifstream in("lottery.in");
ofstream out("lottery.out");

inline int input() {
    int x;
    in >> x;
    return x;
}

int main() {
    double cost = input();
    int m = input();
    double choice = input();
    double prise = input();
    double currentProbability = 1 / choice;
    double expectedValue = 0;
    for (int i = 0; i < m - 1; i++) {
        double newChoice = input();
        double newPrize = input();
        expectedValue += (currentProbability * prise * (newChoice - 1) / newChoice);
        currentProbability *= (1 / newChoice);
        prise = newPrize;
        choice = newChoice;
    }
    expectedValue += (prise * currentProbability);
    out.precision(15);
    out << cost - expectedValue << endl;
    in.close();
    out.close();
}