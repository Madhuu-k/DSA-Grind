#include<iostream>
#include<vector>
using namespace std;

vector<int> partitionLabel(string s) {
    vector<int> last(26);
    for (int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            res.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return res;
}

int main() {
    vector<int> result;
    string s = "MadhuTheGreat";
    result = partitionLabel(s);
    for (int x : result) {
        cout << x << endl;
    }
    return 0;
}