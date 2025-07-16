#include<iostream>
#include<string>
using namespace std;

void permuteString(string& str, int index) {
    if (index == str.length()) {
        cout << str << endl;
        return;
    }

    for (int  i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        permuteString(str, index + 1);
        swap(str[index], str[i]);
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    permuteString(str, 0);
    return 0;
}