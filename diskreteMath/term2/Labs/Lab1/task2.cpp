#include <iostream>
#include <cmath>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;

ifstream in("shooter.in");
ofstream out("shooter.out");

int main() {
    double n, m, k;
    in >> n >> m >> k;
    double sum = 0;
    double candidate = 0;
    for (int i = 0; i < n; i++) {
        double current;
        in >> current;
        current = 1 - current;
        current = pow(current, m);
        if (i == k - 1) {
            candidate = current;
        }
        sum += current;
    }
    out.precision(15);
    out << candidate / sum << endl;
    in.close();
    out.close();
}