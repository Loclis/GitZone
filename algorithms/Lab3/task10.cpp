#include<iostream>
#include<fstream>
#include<vector>

#define ll long long

using namespace std;

ifstream in("nice.in");
ofstream out("nice.out");

inline int input(){
    int answer;
    in >> answer;
    return answer;
}

bool isRelated(int first, int second, int n){
    for (int index = 0; index < n - 1; index++){
        int sum = ((first >> index) % 2) + ((second >> index) % 2) +
                  ((first >> (index + 1)) % 2) + ((second >> (index + 1)) % 2);
        if ((sum == 4) || (sum == 0)) {
            return false;
        }
    }
    return true;
}

int main(){
    int a = input(); int b = input();
    int m = min(a, b); int n = max(a, b);
    int maxMask = (1 << m) - 1;
    vector<int> dinamicStatus(maxMask + 1, 0);
    for (int currentMask = 0; currentMask <= maxMask; currentMask++){
        dinamicStatus[currentMask] = 1;
    }
    /*for (int i = 0; i < isRelated.size(); i++){
        for (int j = 0; j < isRelated[i].size(); j++){
            out << ((isRelated[i][j]) ? 1 : 0) << ' ';
        }
        out << endl;
    }*/
    vector<int> newStatus;
    for (int column = 0; column < (n - 1); column++){
        newStatus.assign(maxMask + 1, 0);
        for (int currentMask = 0; currentMask <= maxMask; currentMask++){
            for (int nextMask = 0; nextMask <= maxMask; nextMask++){
                if (!isRelated(currentMask, nextMask, m)) continue;
                newStatus[nextMask] += dinamicStatus[currentMask];
            }
        }
        dinamicStatus = newStatus;
    }
    int answer = 0;
    for (int mask = 0; mask <= maxMask; mask++){
        answer += dinamicStatus[mask];
    }
    out << answer << endl;
    in.close();
    out.close();
}