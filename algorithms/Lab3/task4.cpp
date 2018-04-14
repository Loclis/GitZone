#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

inline string input(){
    string answer;
    in >> answer;
    return answer;
}

int main(){
    string text = "$"; text += input();
    string pattern = "$"; pattern += input();
    vector<vector<int>> prefixDistance(text.size(), vector<int>(pattern.size()));
    prefixDistance[0][0] = 0;
    for (int i = 1; i < text.size(); i++){
        prefixDistance[i][0] = i;
    }
    for (int j = 1; j < pattern.size(); j++){
        prefixDistance[0][j] = j;
    }
    for (int i = 1; i < text.size(); i++){
        for (int j = 1; j < pattern.size(); j++){
            if (pattern[j] == text[i]) prefixDistance[i][j] = prefixDistance[i - 1][j - 1];
            else
                prefixDistance[i][j] = min(prefixDistance[i][j - 1], min(prefixDistance[i - 1][j], prefixDistance[i - 1][j - 1])) + 1;
        }
    }
    out << prefixDistance[text.size() - 1][pattern.size() - 1] << endl;
    in.close();
    out.close();
}