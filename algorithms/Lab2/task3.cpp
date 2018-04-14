#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
struct stack{
private:
    vector<T> data;
public:
    stack(){
        data.resize(0);
    }
    void push(T value){
        data.push_back(value);
    }
    T back(){
        return data[data.size() - 1];
    }
    T pop(){
        T value = back();
        data.pop_back();
        return value;
    }
    size_t size(){
        return data.size();
    }
};

fstream in("postfix.in");
ofstream out("postfix.out");

int main(){
    stack<int> st;
    string s;
    while (in >> s){
        if (s == "+"){
            int b = st.pop();
            int a = st.pop();
            st.push(a + b);
            continue;
        }
        if (s == "-"){
            int b = st.pop();
            int a = st.pop();
            st.push(a - b);
            continue;
        }
        if (s == "*"){
            int b = st.pop();
            int a = st.pop();
            st.push(a * b);
            continue;
        }
        st.push(stoi(s));
    }
    out << st.back() << endl;
    in.close();
    out.close();
}