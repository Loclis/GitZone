#include<iostream>
#include<fstream>

using namespace std;

ifstream in("bureaucracy.in");
ofstream out("bureaucracy.out");

template<typename T>
struct Queue{
private:
    const static size_t MAX_SIZE = 1e5;
    size_t size;
    int start, end;
    T data[MAX_SIZE];
public:
    Queue(){
        size = 0;
        start = 0;
        end = 0;
    }
    void pushTail(T value){
        data[end++] = value;
        if (end == MAX_SIZE) end = 0;
        size++;
    }
    T extractNext(){
        T answer = data[start++];
        if (start == MAX_SIZE) start = 0;
        size--;
        return answer;
    }
    size_t Size(){
        return size;
    }
};

int main(){
    Queue<int> q;
    int n, m; in >> n >> m;
    for (; n > 0; n--){
        int customer; in >> customer;
        q.pushTail(customer);
    }
    for (; m > 0 && q.Size() > 0; m--){
        int currentCustomer = q.extractNext() - 1;
        if (currentCustomer > 0) q.pushTail(currentCustomer);
    }
    if (q.Size() == 0){
        out << -1 << endl;
        in.close();
        out.close();
        return 0;
    }
    out << q.Size() << endl;
    while (q.Size() > 0){
        out << q.extractNext() << ' ';
    }
    out << endl;
    in.close();
    out.close();
}