#include<iostream>
#include <cstring>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    bool result = isPalindrome(s);
    cout << "The string " << s << "is palindrome: " << result << endl;
    return 0;
}