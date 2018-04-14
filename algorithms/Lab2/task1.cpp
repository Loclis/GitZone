#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ifstream in("decode.in");
    ofstream out("decode.out");
    string s;
    in >> s;
    vector<char> characters;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        characters.push_back(c);
        while (characters.size() >= 2 && characters[characters.size() - 1] == characters[characters.size() - 2]){
            characters.pop_back();
            characters.pop_back();
        }
    }
    for (int i = 0; i < characters.size(); i++){
        out << characters[i];
    }
    out << endl;
    in.close();
    out.close();
}
