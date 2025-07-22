#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    string s1 = "anagram";
    string s2 = "nagaram";
    for (char c : s1) freq1[c]++;
    for (char c : s2) freq2[c]++;
    if (freq1 == freq2) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}