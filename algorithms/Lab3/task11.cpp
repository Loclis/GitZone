#include<iostream>
#include<fstream>
#include<vector>
#define INF 1e4

using namespace std;

ifstream in("skyscraper.in");
ofstream out("skyscraper.out");

inline int input(){
    int x;
    in >> x;
    return x;
}

int main(){
    int n = input(); int maxWeight = input();
    vector<int> weight(n);
    for (int i = 0; i < weight.size(); i++){
        weight[i] = input();
    }
    int finalMask = (1 << n) - 1;
    vector<pair<int, int>> dinamicStatus(finalMask + 1, pair<int, int>(INF, INF));
    vector<pair<int, bool>> home(finalMask + 1, pair<int, bool>(-1, false));
    dinamicStatus[0] = make_pair(0, 0);
    for (int currentMask = 0; currentMask < finalMask; currentMask++){
        for (int index = 0; index < n; index++){
            bool wasUsed = ((currentMask >> index) % 2 == 1);
            if (wasUsed) continue;
            pair<int, int> currentStatus = dinamicStatus[currentMask];
            int newMask = (currentMask ^ (1 << index));
            pair<int, int> newStatus;
            if (currentStatus.second + weight[index] <= maxWeight){
                newStatus.first = currentStatus.first;
                newStatus.second = currentStatus.second + weight[index];
                if (newStatus <= dinamicStatus[newMask]){
                    dinamicStatus[newMask] = newStatus;
                    home[newMask].first = index;
                    home[newMask].second = false;
                }
            } else{
                newStatus.first = currentStatus.first + 1;
                newStatus.second = weight[index];
                if (newStatus <= dinamicStatus[newMask]){
                    dinamicStatus[newMask] = newStatus;
                    home[newMask].first = index;
                    home[newMask].second = true;
                }
            }
        }
    }
    out << dinamicStatus[finalMask].first + (dinamicStatus[finalMask].second != 0) << endl;
    vector<int> way;
    while (home[finalMask].first != -1){
        way.push_back(home[finalMask].first + 1);
        if (home[finalMask].second){
            out << way.size() << ' ';
            for (int i = 0; i < way.size(); i++){
                out << way[i] << ' ';
            }
            out << endl;
            way.clear();
        }
        finalMask = (finalMask ^ (1 << home[finalMask].first));
    }
    if (way.size() != 0){
        out << way.size() << ' ';
        for (int i = 0; i < way.size(); i++){
            out << way[i] << ' ';
        }
        out << endl;
    }
    in.close();
    out.close();
}