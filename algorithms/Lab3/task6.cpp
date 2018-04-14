#include<iostream>
#include<string>
#include<vector>
#include<utility>
#define INF 1e4

using namespace std;

inline string input(){
    string answer;
    getline(cin, answer);
    return answer;
}

char getClosure(char x){
    if (x == '(') return ')';
    if (x == '[') return ']';
    if (x == '{') return '}';
    return ' ';
}

int main(){
    string sequence = input();
    if (sequence.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dinamicStatus(sequence.size(), vector<int>(sequence.size(), INF));
    for (int i = 0; i < sequence.size(); i++){
        dinamicStatus[i][i] = 1;
    }
    for (int i = sequence.size() - 1; i >= 0; i--){
        int x = 10;
        for (int j = i + 1; j < sequence.size(); j++){
            dinamicStatus[i][j] = min(dinamicStatus[i][j], 1 + dinamicStatus[i + 1][j]);
            for (int k = i + 1; k <= j; k++){
                if (sequence[k] == getClosure(sequence[i])){
                    int currentStatus = 0;
                    int l1 = i + 1; int r1 = k - 1;
                    int l2 = k + 1; int r2 = j;
                    if (l1 <= r1) currentStatus += dinamicStatus[l1][r1];
                    if (l2 <= r2) currentStatus += dinamicStatus[l2][r2];
                    dinamicStatus[i][j] = min(dinamicStatus[i][j], currentStatus);
                }
            }
        }
    }
    cout << (sequence.size() - dinamicStatus[0][sequence.size() - 1]) << endl;
}