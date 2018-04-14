#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("hemoglobin.in");
ofstream out("hemoglobin.out");

template<typename T>
struct Stack{
private:
    vector<T> data;
    vector<T> sumData;
public:
    Stack(){
        data.resize(0);
        sumData.resize(0);
    }
    void push(T value){
        if (data.size() == 0){
            data.push_back(value);
            sumData.push_back(value);
            return;
        }
        T newSum = sumData[sumData.size() - 1] + value;
        data.push_back(value);
        sumData.push_back(newSum);
    }
    T pop(){
        T answer = data[data.size() - 1];
        data.pop_back(); sumData.pop_back();
        return answer;
    }
    T getSumOfK(int k){
        int start = data.size() - k - 1;
        if (start == -1) return sumData[sumData.size() - 1];
        else
            return sumData[sumData.size() - 1] - sumData[start];
    }
};

int main(){
    Stack<int> st;
    int n; in >> n;
    for (; n > 0; n--){
        char command; in >> command;
        if (command == '+'){
            int x; in >> x;
            st.push(x);
        }
        if (command == '-'){
            out << st.pop() << endl;
        }
        if (command == '?'){
            int x; in >> x;
            out << st.getSumOfK(x) << endl;
        }
    }
    in.close();
    out.close();
}
