#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<utility>
#include<string>

using namespace std;

ifstream in("formation.in");
ofstream out("formation.out");

template<typename T>
struct node{
    node(){}
    T value;
    node *prev, *next;
};

template<typename T>
struct list{
    node<T>* head;
    size_t size;
    node<T> set[75000];
    vector<int> free;
    map<T, int> position;
    int getPlace(){
        if (free.size() == 0)
            return size++;
        int answer = free.back();
        free.pop_back();
        return answer;
    }
    list(){
        size = 1;
        head = new node<T>();
        head->value = 0;
        set[0].value = 1;
        head->next = &set[0]; head->prev = &set[0];
        set[0].next = head; set[0].prev = head;
    }
    void putLeft(int who, int landmark){
        node<T>* landmarkPointer = &set[position[landmark]];
        int newPlace = getPlace();
        position[who] = newPlace;
        set[newPlace].next = landmarkPointer;
        set[newPlace].prev = landmarkPointer->prev;
        set[newPlace].value = who;
        landmarkPointer->prev->next = &(set[newPlace]);
        landmarkPointer->prev = &(set[newPlace]);
    }
    void putRight(int who, int landmark){
        node<T>* landmarkPointer = &set[position[landmark]];
        int newPlace = getPlace();
        position[who] = newPlace;
        set[newPlace].prev = landmarkPointer;
        set[newPlace].next = landmarkPointer->next;
        set[newPlace].value = who;
        landmarkPointer->next->prev = &(set[newPlace]);
        landmarkPointer->next = &(set[newPlace]);
    }
    void remove(int who){
        node<T> *landmark = &(set[position[who]]);
        landmark->prev->next = landmark->next;
        landmark->next->prev = landmark->prev;
        free.push_back(position[who]);
        position[who] = -1;
    }
    pair<int, int> getNeighbours(int who){
        node<T> *landmark = &set[position[who]];
        return make_pair(landmark->prev->value, landmark->next->value);
    }
};
int main(){
    list<int> a;
    int n, m;
    in >> n >> m;
    for (; m > 0; m--){
        string command; in >> command;
        if (command == "left"){
            int x, y; in >> x >> y;
            a.putLeft(x, y);
        }
        if (command == "right"){
            int x, y; in >> x >> y;
            a.putRight(x, y);
        }
        if (command == "leave"){
            int x; in >> x;
            a.remove(x);
        }
        if (command == "name"){
            int x; in >> x;
            pair<int, int> neighbours = a.getNeighbours(x);
            out << neighbours.first << ' ' << neighbours.second << endl;
        }
    }
    in.close();
    out.close();
}