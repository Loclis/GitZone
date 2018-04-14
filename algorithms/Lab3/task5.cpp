#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

inline int input(){
    int x;
    cin >> x;
    return x;
}

int main(){
    int n = input();
    vector<int> price(n);
    for (int i = 0; i < n; i++){
        price[i] = input();
    }
    vector<vector<int>> bestPayment(n + 1, vector<int>(n + 2, INF));
    vector<vector<pair<int, int>>> home(n + 1, vector<pair<int, int>>(n + 2, pair<int, int>(-1, -1)));
    bestPayment[0][0] = 0;
    for (int i = 1; i <= n ; i++){
        for (int j = 0; j <= n; j++){
            if ((j != 0) && price[i - 1] > 100){
                if (bestPayment[i - 1][j - 1] + price[i - 1] < bestPayment[i][j]){
                    bestPayment[i][j] = bestPayment[i - 1][j - 1] + price[i - 1];
                    home[i][j].first = i - 1;
                    home[i][j].second = j - 1;
                }
            }
            if (bestPayment[i - 1][j] + price[i - 1] < bestPayment[i][j]){
                bestPayment[i][j] = bestPayment[i - 1][j] + price[i - 1];
                home[i][j].first = i - 1;
                home[i][j].second = j;
            }
            if (bestPayment[i - 1][j + 1] < bestPayment[i][j]){
                bestPayment[i][j] = bestPayment[i - 1][j + 1];
                home[i][j].first = i - 1;
                home[i][j].second = j + 1;
            }
        }
    }
    int bestX = n; int bestY = 0;
    int bestAnswer = bestPayment[bestX][0];
    for (int j = 0; j <= n; j++){
        if (bestPayment[n][j] <= bestAnswer){
            bestAnswer = bestPayment[n][j];
            bestY = j;
        }
    }
    cout << bestAnswer << endl;
    cout << bestY << ' ';
    vector<int> way;
    int wasUsed = 0;
    while (bestX != -1){
        pair<int, int> next = home[bestX][bestY];
        if ((next.first == bestX - 1) && (next.second == bestY + 1)){
            way.push_back(bestX - 1);
            wasUsed++;
        }
        bestX = next.first; bestY = next.second;
    }
    cout << wasUsed << endl;
    for (int i = way.size() - 1; i >= 0; i--){
        cout << way[i] + 1 << endl;
    }
}