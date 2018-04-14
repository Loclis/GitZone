#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

fstream in("stack-min.in");
ofstream out("stack-min.out");

template<typename T>
struct stack{
private:
    vector<T> data;
    vector<T> minData;
public:
    stack(){
        data.resize(0);
        minData.resize(0);
    }
    void push(T value){
        if (data.size() == 0){
            data.push_back(value);
            minData.push_back(value);
        }
        else{
            minData.push_back(min(data[data.size() - 1], minData[minData.size() - 1]));
            data.push_back(value);
        }
    }
    T back(){
        return data[data.size() - 1];
    }
    T getMin(){
        return min(data[data.size() - 1], minData[minData.size() - 1]);
    }
    T pop(){
        T value = back();
        data.pop_back();
        minData.pop_back();
        return value;
    }
    size_t size(){
        return data.size();
    }
};

int main(){
    int n; in >> n;
    stack<int> st;
    for (; n > 0; n--){
        int command; in >> command;
        if (command == 1){
            int value; in >> value;
            st.push(value);
        }
        if (command == 2){
            st.pop();
        }
        if (command == 3){
            out << st.getMin() << endl;
        }
    }
    in.close();
    out.close();
}