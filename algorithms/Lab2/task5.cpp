#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

ifstream in("dsu.in");
ofstream out("dsu.out");

struct dsu{
    vector<int> p, minP, maxP, size, h;
    dsu(int n){
        p.resize(n + 1); minP.resize(n + 1); maxP.resize(n + 1);
        for (int i = 0; i < p.size(); i++){
            p[i] = i; minP[i] = i; maxP[i] = i;
        }
        size.assign(n + 1, 1);
        h.assign(n + 1, 0);
    }
    int get(int v){
        for(; p[v] != v; v = p[v]);
        return v;
    }
    void unite(int x, int y){
        x = get(x);
        y = get(y);
        if (x == y) return;
        if (h[y] > h[x])
            swap(x, y);
        p[y] = x;
        minP[x] = min(minP[x], minP[y]);
        maxP[x] = max(maxP[x], maxP[y]);
        size[x] += size[y];
        h[x] = max(h[x], h[y] + 1);
    }
};

int main(){
    int n; in >> n;
    dsu set(n);
    string command;
    while (in >> command){
        if (command == "union"){
            int x, y; in >> x >> y;
            set.unite(x, y);
        }
        else{
            int x; in >> x;
            x = set.get(x);
            out << set.minP[x] << ' ' << set.maxP[x] << ' ' << set.size[x] << endl;
        }
    }
    in.close();
    out.close();
}