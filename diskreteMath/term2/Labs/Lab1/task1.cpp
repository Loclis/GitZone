#include <iostream>
#include <vector>
#include <fstream>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::endl;

ifstream in("exam.in");
ofstream out("exam.out");

inline int input() {
    int x;
    in >> x;
    return x;
}

int main() {
    double k = input();
    double n = input();
    double answer = 0;
    for (; k > 0; k--) {
        double p = input();
        double m = input();
        answer += (p / n * m / 100);
    }
    out.precision(7);
    out << answer << endl;
    in.close();
    out.close();
}