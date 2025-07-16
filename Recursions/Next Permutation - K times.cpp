#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string nextPermutation(string str) {
    int n = str.size();
    int i = n - 2;

    while(i >= 0 && str[i] >= str[i+1]) i--;
    if(i < 0) return "done";  // Signal end of permutations

    int j = n - 1;
    while(str[j] <= str[i]) j--;
    swap(str[i], str[j]);
    reverse(str.begin() + i + 1, str.end());

    return str;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    vector<string> result;
    result.push_back(str); // send default string
    while (true) {
        string next = nextPermutation(str);
        if (next == "done") break;
        result.push_back(next);
        str = next;
    }

    for (string s : result) cout << s << " " << endl;
    return 0;
}