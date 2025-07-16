#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void generateStringSubsets(string& str, string current, int index) {
    if (index == str.size()) {
        cout << "[" << current << "]" << endl;
        return;
    }

    generateStringSubsets(str, current + str[index], index + 1); // " "  + "e" =>
    generateStringSubsets(str, current, index + 1);
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    generateStringSubsets(str, " ", 0);
    return 0;
}