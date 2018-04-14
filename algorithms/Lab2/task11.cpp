#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ifstream in("kenobi.in");
ofstream out("kenobi.out");

template<typename T>
struct Node{
    Node(){}
    T value;
    Node *prev, *next;
};
template<typename T>
struct SuperStack{
    Node<T> *topHead, *backHead;
    size_t backSize, topSize, size;
    SuperStack(){
        topHead = new Node<T>();
        topHead->next = topHead; topHead->prev = topHead; topHead->value = 0;
        backHead = new Node<T>();
        backHead->next = backHead; backHead->prev = backHead; backHead->value = 0;
        backSize = 0, topSize = 0, size = 0;
    }
    void pushTopHead(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value; newElement->next = topHead->next; newElement->prev = topHead;
        topHead->next->prev = newElement;
        topHead->next = newElement;
    }
    void pushTopTail(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value; newElement->next = topHead; newElement->prev = topHead->prev;
        topHead->prev->next = newElement; topHead->prev = newElement;
    }
    void pushBackHead(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value; newElement->next = backHead->next; newElement->prev = backHead;
        backHead->next->prev = newElement;
        backHead->next = newElement;
    }
    void pushBackTail(T value){
        Node<T> *newElement = new Node<T>();
        newElement->value = value; newElement->next = backHead; newElement->prev = backHead->prev;
        backHead->prev->next = newElement; backHead->prev = newElement;
    }
    T extractTopHead(){
        T answer = topHead->next->value;
        topHead->next->next->prev = topHead;
        topHead->next = topHead->next->next;
        return answer;
    }
    T extractTopTail(){
        T answer = topHead->prev->value;
        topHead->prev->prev->next = topHead;
        topHead->prev = topHead->prev->prev;
        return answer;
    }
    T extractBackHead(){
        T answer = backHead->next->value;
        backHead->next->next->prev = backHead;
        backHead->next = backHead->next->next;
        return answer;
    }
    T extractBackTail(){
        T answer = backHead->prev->value;
        backHead->prev->prev->next = backHead;
        backHead->prev = backHead->prev->prev;
    }
    void promote(){
        pushTopTail(extractBackHead());
    }
    void demote(){
        pushBackHead(extractTopTail());
    }
    void push(T value){
        pushTopHead(value); size++; topSize++;
        if (size % 2 == 0 && topSize > backSize){
            demote();
            topSize--;
            backSize++;
        }
    }
    T pop(){
        T answer = extractTopHead();
        topSize--;
        while (topSize < backSize){
            promote();
            topSize++;
            backSize--;
        }
        size--;
        return answer;
    }
    void printStack(){
        //out << "List 2::";
        for (Node<T> *i = backHead->prev; i != backHead; i = i->prev){
            out << i->value << ' ';
        }
        //out << endl;
        //out << "List 1::";
        for (Node<T> *i = topHead->prev; i != topHead; i = i->prev){
            out << i->value << ' ';
        }
        out << endl;
    }
    void superSwap(){
        swap(topHead, backHead);
        swap(topSize, backSize);
        while(topSize < backSize){
            promote();
            topSize++;
            backSize--;
        }
    }
};

int main(){
    SuperStack<int> st;
    int n; in >> n;
    for (; n > 0; n--){
        string command; in >> command;
        if (command == "add"){
            int x; in >> x;
            st.push(x);
        }
        if (command == "take" && st.size != 0) st.pop();
        if (command == "mum!") st.superSwap();
        //st.printStack();
    }
    out << st.size << endl;
    if (st.size != 0) st.printStack();
    in.close();
    out.close();
}