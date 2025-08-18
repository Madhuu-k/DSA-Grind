#include<iostream>
#include<algorithm>
#include <sstream>
#include<vector>
using namespace std;

struct Trie {
    Trie* children[26];
    bool isEnd;
    Trie() {
        fill(begin(children), end(children), nullptr);
        isEnd = false;
    }
};

Trie* root = new Trie();

void insert(string word) {
    Trie* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node -> children[idx]) node -> children[idx] = new Trie();
        node = node -> children[idx];
    }
    node -> isEnd = true;
}

string replace(string word) {
    Trie* node = root;
    string prefix = "";
    for (char c : word) {
        int idx = c - 'a';
        if (!node -> children[idx]) return word;
        node = node -> children[idx];
        prefix += c;
        if (node -> isEnd) return prefix;
    }
    return word;
}

string replaceWord(vector<string>& dict, string sentance) {
    for (string& w : dict) insert(w);
    stringstream ss(sentance);
    string word, ans = "";
    while (ss >> word) {
        if (!ans.empty()) ans += " ";
        ans += replace(word);
    }
    return ans;
}

int main() {
    vector<string> dict = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    string result = replaceWord(dict, sentence);

    cout << result << endl;
    return 0;
}
