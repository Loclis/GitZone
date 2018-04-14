#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#define EPS 1e-4
#define INF 1e9
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

ifstream in("markchain.in");
ofstream out("markchain.out");

inline double input() {
    double x;
    in >> x;
    return x;
}

void swap(double& a, double& b) {
    double c = a;
    a = b;
    b = c;
}

void calcLinearSystem (vector<vector<double>> matrix, vector<double>& result) {
    int border = matrix[0].size() - 1;
    vector<int> position(border, INF);
    for (int i = 0, j = 0; (i < matrix.size()) && (j < border); i++) {
        int maxK = i;
        for (int k = i; k < matrix.size(); k++) {
            if (fabs(matrix[k][j]) > fabs(matrix[maxK][j])) {
                maxK = k;
            }
        }
        if (fabs (matrix[maxK][j]) < EPS) {
            continue;
        }
        for (int k = j; k < matrix[i].size(); k++) {
            swap(matrix[maxK][k], matrix[i][k]);
        }
        position[j] = i;
        for (int k = 0; k < matrix.size(); k++)
            if (i != k) {
                double div = matrix[k][j] / matrix[i][j];
                for (int p = j; p < matrix[i].size(); p++)
                    matrix[k][p] -= matrix[i][p] * div;
            }
        j++;
    }

    result.resize(border);
    for (int i = 0; i < border; i++) {
        if (position[i] != INF) {
            result[i] = matrix[position[i]][border] / matrix[position[i]][i];
        }
    }
}

void test() {
    int n, m;
    cin >> n >> m;
    vector<vector<double >> a(n, vector<double >(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<double> ans;
    calcLinearSystem(a, ans);
    cout.precision(15);
    for (int i = 0; i < ans.size(); i++) {
        cout << ((fabs(ans[i]) < EPS) ? 0 : ans[i]) << endl;
    }
    cout << "===========";
}

int main() {
    int n = static_cast<int>(input());
    vector<vector<double>> matrix(n, vector<double>(n + 1));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            matrix[i][j] = input();
        }
    }
    for (int j = 0; j < n + 1; j++) {
        matrix[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        matrix[i][i] -= 1;
    }
    vector<double> answer;
    calcLinearSystem(matrix, answer);
    out.precision(15);
    for (int i = 0; i < answer.size(); i++) {
        out << ((fabs(answer[i]) < EPS) ? 0 : answer[i]) << endl;
    }
    in.close();
    out.close();
}