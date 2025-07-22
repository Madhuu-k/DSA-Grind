#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    string name = "MadhuSudhanRao";
    unordered_map<char, int> freq;
    for (char c : name) {
        freq[c]++;

    }
    for (auto i : freq) {
        if (i.second == 1) cout << i.first << ": " << i.second << endl;
    }
    return 0;
}