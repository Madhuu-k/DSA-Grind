#include<iostream>
#include<vector>
#include<algorithm>
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
string stream = "";

void insert(string word) {
    Trie* node = root;
    for (int i = word.size() - 1; i >= 0; i--) {
        int idx = word[i] - 'a';
        if (!node -> children[idx]) node -> children[idx] = new Trie();
        node = node -> children[idx];
    }
    node -> isEnd = true;
}

bool query(char letter) {
    stream.push_back(letter);
    Trie* node = root;
    for (int i = stream.size() - 1; i >= 0 && node; i--) {
        int idx = stream[i] - 'a';
        node = node -> children[idx];
        if (!node) return false;
        if (node -> isEnd) return true;
    }
    return false;
}

int main() {
    vector<string> words = {"cd", "f", "kl"};
    for (auto &w : words) insert(w);

    vector<char> queries = {'a','b','c','d','e','f','g','h','i','j','k','l'};

    for (char q : queries) {
        bool ans = query(q);
        cout << "query('" << q << "') -> " << (ans ? "true" : "false") << endl;
    }

    return 0;
}