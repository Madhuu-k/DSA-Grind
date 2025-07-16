#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>> M, int a, int b) {
    return M[a][b] == 1;
}

int getCelebrity(vector<vector<int>> M, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if (knows(M, a, b)) st.push(b);
        else st.push(a);
    }
    int candidate = st.top();

    for (int i = 0; i < n; i++) {
        if (knows(M, candidate, i) || !knows(M, i, candidate)) return -1;
    }
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    int n = 3;

    int celeb = getCelebrity(M, n);
    if (celeb == -1) cout << "No Celebrity";
    else cout << "Celebrity ID: " << celeb;

    return 0;
}