#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
public:
    void push(int x) {
        st.push((x));
        if (minStack.empty() || minStack.top() >= x) minStack.push(x);
    }
    void pop() {
        if (st.top() == minStack.top()) minStack.pop();
        st.pop();
    }
    int top() {return st.top();}
    int getMin() {return minStack.top(); }
};

int main() {
    MinStack ms;
    ms.push(10);
    ms.push(4);
    ms.push(13);
    ms.push(8);
    ms.pop();
    ms.pop();
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin();
    return 0;
}