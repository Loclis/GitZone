#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ifstream in("hospital.in");
ofstream out("hospital.out");

template<typename T>
struct Node{
    Node(){}
    T value;
    Node *prev, *next;
};
template<typename T>
struct SuperQueue{
    Node<T> *topHead, *backHead;
    size_t backSize, topSize, size;
    SuperQueue(){
        topHead = new Node<T>();
        topHead->next = topHead; topHead->prev = topHead; topHead->value = 0;
        backHead = new Node<T>();
        backHead->next = backHead; backHead->prev = backHead; backHead->value = 0;
        backSize = 0, topSize = 0, size = 0;
    }
    void pushTopTail(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value;
        newElement->next = topHead->next;
        newElement->prev = topHead;
        topHead->next->prev = newElement;
        topHead->next = newElement;
    }
    void pushBackTail(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value;
        newElement->next = backHead->next;
        newElement->prev = backHead;
        backHead->next->prev = newElement;
        backHead->next = newElement;
    }
    void pushTopHead(T value){
        Node<T>* newElement = new Node<T>();
        newElement->value = value;
        newElement->prev = topHead->prev;
        newElement->next = topHead;
        topHead->prev->next = newElement;
        topHead->prev = newElement;
    }
    void pushBackHead(T value){
        Node<T>* newElement = new Node<T>();
        newElement->value = value;
        newElement->prev = backHead->prev;
        newElement->next = backHead;
        backHead->prev->next = newElement;
        backHead->prev = newElement;
    }
    T extractTopHead(){
        T answer = topHead->prev->value;
        topHead->prev->prev->next = topHead;
        topHead->prev = topHead->prev->prev;
        return answer;
    }
    T extractTopTail(){
        T answer = topHead->next->value;
        topHead->next->next->prev = topHead;
        topHead->next = topHead->next->next;
        return answer;
    }
    T extractBackTail(){
        T answer = backHead->next->value;
        backHead->next->next->prev = backHead;
        backHead->next = backHead->next->next;
        return answer;
    }
    T extractBackHead(){
        T answer = backHead->prev->value;
        backHead->prev->prev->next = backHead;
        backHead->prev = backHead->prev->prev;
        return answer;
    }
    void promote(){
        pushTopTail(extractBackHead());
    }
    void demote(){
        pushBackHead(extractTopTail());
    }
    void pushToTail(int value){
        pushBackTail(value); size++; backSize++;
        if (backSize > topSize){
            promote();
            topSize++; backSize--;
        }
    }
    void pushToMiddle(int value){
        if (topSize == size / 2){
            pushTopTail(value);
            topSize++;
        } else{
            pushBackHead(value);
            backSize++;
        }
        size++;
    }
    T getNext(){
        T answer = extractTopHead(); topSize--; size--;
        if (topSize < backSize){
            promote();
            topSize++; backSize--;
        }
        return answer;
    }
    void PrintList(){
        out << "List 1:: ";
        for (Node<T> *i = topHead->prev; i != topHead; i = i->prev){
            out << i->value << ' ';
        }
        out << endl << "List 2:: ";
        for (Node<T> *i = backHead->prev; i != backHead; i = i->prev){
            out << i->value << ' ';
        }
        out << endl;
    }
};

int main(){
    SuperQueue<int> q;
    int n; in >> n;
    for (; n > 0; n--){
        string command; in >> command;
        if (command == "+"){
            int x; in >> x;
            q.pushToTail(x);
        }
        if (command == "*"){
            int x; in >> x;
            q.pushToMiddle(x);
        }
        if (command == "-"){
            out << q.getNext() << endl;
        }
        if (command == "print") q.PrintList();
        //q.PrintList();
    }
    in.close();
    out.close();
}