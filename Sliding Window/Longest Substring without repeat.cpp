#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++) {
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    cout << "Enter the string: ";
    string s;
    cin >> s;
    int result = lengthOfLongestSubstring(s);
    cout << "Length of Longest Substring is: " << result;
    return 0;

}