#include<iostream>
#include<vector>
#define ll long long
#define INF 1e10

using namespace std;

inline ll input(){
    ll answer;
    cin >> answer;
    return answer;
}

int main(){
    //cout << LLONG_MAX;
    ll n = input(); //ll m = input();
    vector<vector<ll>> road(n, vector<ll>(n));
    for (ll i = 0; i < n; i++){
        for (ll j  = 0; j < n; j++){
            road[i][j] = input();
        }
    }
    /*for (int i = 0; i < m; i++){
        int x = input() - 1; int y = input() - 1; int v = input();
        road[x][y] = v;
        road[y][x] = v;
    }*/
    ll finalMask = (1 << n) - 1;
    //cout << finalMask << endl;
    vector<vector<ll>> dinamicStatus(finalMask + 1, vector<ll>(n, INF));
    vector<vector<ll>> home(finalMask + 1, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++){
        dinamicStatus[1 << i][i] = 0;
    }
    for (ll currentMask = 0; currentMask < finalMask; currentMask++){
        for (ll position = 0; position < n; position++){
            if (dinamicStatus[currentMask][position] == INF) continue;
            for (ll destination = 0; destination < n; destination++){
                if (((currentMask >> destination) % 2 == 1)) continue;
                ll newMask = currentMask ^ (1 << destination);
                ll newStatus = dinamicStatus[currentMask][position] + road[position][destination];
                if (dinamicStatus[newMask][destination] > newStatus){
                    dinamicStatus[newMask][destination] = newStatus;
                    home[newMask][destination] = position;
                }
            }
        }
    }
    ll answer = INF;
    ll realAnswerPosition = -1;
    for (ll i = 0; i < n; i++){
        if (dinamicStatus[finalMask][i] < answer){
            answer = dinamicStatus[finalMask][i];
            realAnswerPosition = i;
        }
    }
    if (answer != INF)
        cout << answer << endl;
    else{
        cout << 0 << endl;
        return 0;
    }
    vector<ll> way;
    while (realAnswerPosition != -1){
        way.push_back(realAnswerPosition);
        ll next = home[finalMask][realAnswerPosition];
        finalMask = finalMask ^ (1 << realAnswerPosition);
        realAnswerPosition = next;
    }
    for (ll i = way.size() - 1; i >= 0; i--){
        cout << way[i] + 1 << ' ';
    }
    cout << endl;
}