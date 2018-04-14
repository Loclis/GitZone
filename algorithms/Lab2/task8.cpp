#include<iostream>
#include<fstream>
#include<utility>
#include<vector>

using namespace std;

ifstream in("saloon.in");
ofstream out("saloon.out");

template<typename T>
struct Node{
    Node<T> *next, *prev;
    T value;
};
template<typename T>
struct Queue{
private:
    Node<T> *head;
    size_t size;
public:
    Queue(){
        head = new Node<T>();
        size = 0;
        head->next = head;
        head->prev = head;
    }
    T getNext(){
        return head->prev->value;
    }
    void pushTail(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value;
        newElement->prev = head;
        newElement->next = head->next;
        head->next->prev = newElement;
        head->next = newElement;
        size++;
    }
    T extractNext(){
        T answer = getNext();
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        size--;
        return answer;
    }
    T getLast(){
        return head->next->value;
    }
    size_t Size(){
        return size;
    }
};

int main(){
    Queue<pair<int, pair<int, int>>> q;
    int n; in >> n;
    vector<int> answer(n);
    for (int i = 0; i < n; i++){
        int hour, minute, nerves;
        in >> hour >> minute >> nerves;
        int realTime = hour * 60 + minute;
        while (q.Size() != 0 && q.getNext().second.second <= realTime){
            pair<int, pair<int, int>> ready = q.extractNext();
            answer[ready.first] = ready.second.second;
        }
        if (q.Size() > nerves) answer[i] = realTime;
        else{
            if (q.Size() == 0) q.pushTail(make_pair(i, make_pair(realTime, realTime + 20)));
            else{
                int exitTime = q.getLast().second.second + 20;
                q.pushTail(make_pair(i, make_pair(realTime, exitTime)));
            }
        }
    }
    while (q.Size() > 0){
        pair<int, pair<int, int>> visitor = q.extractNext();
        answer[visitor.first] = visitor.second.second;
    }
    for (int i = 0; i < n; i++){
        out << answer[i] / 60 << ' ' << answer[i] % 60 << endl;
    }
    in.close();
    out.close();
}