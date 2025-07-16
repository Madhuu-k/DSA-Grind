#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int evaluatePrefix(string exp) {
    stack<int> st;
    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
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
    int result = evaluatePrefix(exp);
    cout << result << endl;
    return 0;
}
