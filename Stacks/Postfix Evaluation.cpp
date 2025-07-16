#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    for (char c : exp) {
        if (std::isdigit(c)) st.push(c - '0');
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                default: break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    int result = evaluatePostfix(exp);
    cout << result << endl;
    return 0;
}