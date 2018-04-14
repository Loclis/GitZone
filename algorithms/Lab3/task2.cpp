#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define ll long long
#define INF 1e10

using namespace std;

inline ll input(){
    ll x;
    cin >> x;
    return x;
}

ll binarySearch(vector<ll>& elements, ll value){
    ll l = 0; ll r = elements.size() - 1;
    while (r - l > 1){
        ll middle = (l + r) / 2;
        ll q = elements[middle];
        if (q < value) l = middle;
        else
            r = middle;
    }
    if (elements[r] >= value) return r;
    else
        return -1;
}

int main(){
    ll n = input();
    vector<ll> elements(n);
    for (ll i = 0; i < elements.size(); i++){
        elements[i] = input();
    }
    vector<ll> lengthToLastElementDP(n + 1, INF);
    vector<ll> homeland(n + 1, -1);
    vector<ll> lastElementIndex(n + 1, -1);
    lengthToLastElementDP[0] = -INF;
    ll bestAnswer = 0;
    for (ll i = 0; i < elements.size(); i++){
        ll bestPosition = binarySearch(lengthToLastElementDP, elements[i]);
        if ((bestPosition != -1) && (elements[i] < lengthToLastElementDP[bestPosition]) &&(lengthToLastElementDP[bestPosition - 1] < elements[i])){
            lengthToLastElementDP[bestPosition] = elements[i];
            homeland[i] = lastElementIndex[bestPosition - 1];
            lastElementIndex[bestPosition] = i;
            bestAnswer = max(bestAnswer, bestPosition);
        }
    }
    vector<ll> way;
    cout << bestAnswer << endl;
    ll currentIndex = lastElementIndex[bestAnswer];
    while (currentIndex != -1){
        way.push_back(elements[currentIndex]);
        currentIndex = homeland[currentIndex];
    }
    for (ll i = way.size() - 1; i >= 0; i--){
        cout << way[i] << ' ';
    }
    cout << endl;
}