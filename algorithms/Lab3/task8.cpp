#include<iostream>
#include<vector>
//#include<xutility>

using namespace std;

vector<vector<int>> vertex;

inline int input(){
    int x;
    cin >> x;
    return x;
}

pair<int, int> getAnswer(int v){
    pair<int, int> answer(1, 0);
    if (vertex[v].size() == 0) return answer;
    for (int i = 0; i < vertex[v].size(); i++){
        pair<int, int> child = getAnswer(vertex[v][i]);
        answer.first += child.second;
        answer.second += max(child.first, child.second);
    }
    return answer;
}

int main(){
    int n = input();
    int greatGuy = 0;
    vertex.assign(n, vector<int>());
    for (int i = 0; i < n; i++){
        int parent = input();
        if (parent == 0) greatGuy = i;
        else
            vertex[parent - 1].push_back(i);
    }
    pair<int, int> result = getAnswer(greatGuy);
    cout << max(result.first, result.second) << endl;
}