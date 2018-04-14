#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

bool isOpen(int x);
int giveEnd(int x);

ifstream in("brackets.in");
ofstream out("brackets.out");

template<typename T>
class stack
{
private:
    size_t size;
    vector<T> stack_data;
public:
    stack();
    bool push(T x);
    bool pop();
    void Printstack();
    size_t Size(){
        return size;
    }
    T top(){
        return stack_data[size - 1];
    }
};

int main()
{
    string a;
    in >> a;
    stack<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '(' && a[i] != ')' && a[i] != '[' && a[i] != ']'
            && a[i] != '{' && a[i] != '}' && a[i] != '<' && a[i] != '>')
            continue;
        if (isOpen(a[i])) st.push(a[i]);
        else
        {
            if (st.Size() == 0) {out << "NO" << endl; return 0;}
            int prev = st.top();
            if (a[i] == giveEnd(prev)) st.pop();
            else
            {
                out << "NO" << endl;
                return 0;
            }
        }
    }
    if (st.Size() != 0) {out << "NO" << endl; return 0;}
    out << "YES" << endl;
    in.close();
    out.close();
}

bool isOpen(int x)
{
    if (x == '(' || x == '[' || x == '{' || x == '<') return true;
    return false;
}
int giveEnd(int x)
{
    if (x == '(') return ')';
    if (x == '[') return ']';
    if (x == '{') return '}';
    if (x == '<') return '>';
    return -1;
}
template<typename T>
stack<T>::stack()
{
    size = 0;
    stack_data.resize(0);
}
template<typename T>
bool stack<T>::push(T x)
{
    stack_data.push_back(x);
    size++;
    return true;
}
template<typename T>
bool stack<T>::pop()
{
    if (size == 0) return false;
    stack_data.pop_back();
    size--;
    return true;
}
template<typename T>
void stack<T>::Printstack()
{
    if (size == 0) {out << "EMPTY" << endl; return;}
    for (int i = 0; i < stack_data.size(); i++)
        out << stack_data[i] << ' ';
    out << endl;
}