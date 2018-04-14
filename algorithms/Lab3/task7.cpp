#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, string> hint;

inline string input(){
    string answer;
    cin >> answer;
    return answer;
}

char getClosure(char x){
    if (x == '(') return ')';
    if (x == '[') return ']';
    if (x == '{') return '}';
    return '&';
}

string getLongestSubsequence(string sequence){
    if ((sequence.size() == 0) || (sequence.size() == 1))
        return "";
    if (hint.find(sequence) != hint.end())
        return hint[sequence];
    string answer = getLongestSubsequence(sequence.substr(1, answer.size() - 1));
    for (int k = 1; k < sequence.size(); k++){
        if (sequence[k] == getClosure(sequence[0])){
            string left = "";
            string right = "";
            int l1 = 1; int r1 = k - 1;
            int l2 = k + 1; int r2 = sequence.size() - 1;
            if (l1 <= r1) left = getLongestSubsequence(sequence.substr(l1, (r1 - l1) + 1));
            if (l2 <= r2) right = getLongestSubsequence(sequence.substr(l2, (r2 - l2) + 1));
            string currentAnswer = sequence[0] + left + sequence[k] + right;
            if (currentAnswer.size() > answer.size())
                answer = currentAnswer;

        }
    }
    hint[sequence] = answer;
    return answer;
}

int main(){
    string answer = input();
    answer = getLongestSubsequence(answer);
    cout << answer << endl;
    return 0;