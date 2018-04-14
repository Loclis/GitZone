#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

inline int input(){
    int x;
    in >> x;
    return x;
}

int main(){
    int n = input(); int k = input();
    vector<int> money(n);
    vector<int> home(n);
    for (int i = 1; i < n; i++){
        int bestHome = i - 1;
        for (int j = max(0, i - k); j < i; j++){
            if (money[j] > money[bestHome]) bestHome = j;
        }
        money[i] = (i != n - 1) ? money[bestHome] + input() : money[bestHome];
        home[i] = bestHome;
    }
    out << money[n - 1] << endl;
    vector<int> way;
    for (int currentPosition = n - 1; home[currentPosition] != currentPosition; way.push_back(currentPosition + 1), currentPosition = home[currentPosition]);
    way.push_back(1);
    out << way.size() - 1 << endl;
    for (int i = way.size() - 1; i >= 0; i--){
        out << way[i] << ' ';
    }
    out << endl;
    in.close();
    out.close();
}