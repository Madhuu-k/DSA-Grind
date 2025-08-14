#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Trie {
    Trie* children[26];
    vector<string> top;
    bool isEnd;

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class TrieNode {
public:
    Trie* root;
    int K;

    TrieNode(int k) {
        root = new Trie();
        K = k;
    }

    void insert(string word) {
        Trie* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];

            node -> top.insert(lower_bound(node -> top.begin(), node -> top.end(), word), word);
            if (static_cast<int>(node->top.size()) > K) node -> top.pop_back();
        }
        node -> isEnd = true;
    }

    Trie* walk(string& pref) {
        Trie* node = root;
        for (char c : pref) {
            int idx = c - 'a';
            if (!node -> children[idx]) return nullptr;
            node = node -> children[idx];
        }
        return node;
    }
};

int main() {
    int n, q;
    cout << "Enter Number of Words and Suggestions: ";
    cin >> n >> q;
    vector<string> words(n);
    cout << "Enter Words: ";
    for (auto& w : words) cin >> w;
    sort(words.begin(), words.end());
    TrieNode t(5);
    for (auto& w : words) t.insert(w);
    while (q--) {
        string prefix;
        cout << "Enter Prefix: ";
        cin >> prefix;
        Trie* node = t.walk(prefix);
        if (!node || node -> top.empty()) cout << "-1\n";
        else {
            for (int i = 0; i < (int)node -> top.size(); i++) {
                cout << "Suggestion " << i + 1 << ": " << node -> top[i] << "\n";
            }
            cout << "\n";
        }
    }
    return 0;
}