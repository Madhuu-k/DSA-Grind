#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int lengthOfLongestSubstringAfterK(string str, int k){
    if (k > str.length()) return -1;

    int left = 0, maxLen = 0;
    unordered_map<char, int> freq;
    for (int right = 0; right < str.length(); right++) {
        freq[str[right]] ++;

        while (freq.size() > k) {
            freq[str[left]] --;
            if (freq[str[left]] == 0) freq.erase(str[left]);
            left ++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    cout << "Enter String: ";
    string str;
    cin >> str;
    cout << "Enter K Value: ";
    int k;
    cin >> k;
    cout << lengthOfLongestSubstringAfterK(str, k) << endl;
    return 0;
}