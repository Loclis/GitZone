#include<iostream>
#include<vector>
#define ll long long

using namespace std;

inline ll input(){
    ll x;
    cin >> x;
    return x;
}

int main(){
    ll n = input();
    vector<ll> number(10, 1);
    number[0] = 0; number[8] = 0;
    for (ll i = 1; i < n; i++){
        vector<ll> newNumber(10);
        newNumber[1] = (number[6] + number[8]) % (ll)(1e9);
        newNumber[2] = (number[7] + number[9]) % (ll)(1e9);
        newNumber[3] = (number[4] + number[8]) % (ll)(1e9);
        newNumber[4] = (number[3] + number[9] + number[0]) % (ll)(1e9);
        newNumber[5] = 0;
        newNumber[6] = (number[1] + number[7] + number[0]) % (ll)(1e9);
        newNumber[7] = (number[2] + number[6]) % (ll)(1e9);
        newNumber[8] = (number[1] + number[3]) % (ll)(1e9);
        newNumber[9] = (number[2] + number[4]) % (ll)(1e9);
        newNumber[0] = (number[4] + number[6]) % (ll)(1e9);
        number = newNumber;
    }
    ll answer = 0;
    for (ll i = 0; i < 10; i++){
        answer = (number[i] + answer) % (ll)(1e9);
    }
    cout << answer << endl;
}