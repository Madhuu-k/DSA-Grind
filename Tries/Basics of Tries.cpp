#include<iostream>
using namespace std;

struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (node -> children[idx] == nullptr) node -> children[idx] = new TrieNode();
        node = node -> children[idx];
    }
    node -> isEndOfWord = true;
}

bool search(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (node -> children[idx] == nullptr) return false;
        node = node -> children[idx];
    }
    return node -> isEndOfWord;
}

bool startsWith(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (node -> children[idx] == nullptr) return false;
        node = node -> children[idx];
    }
    return true;
}

int main() {
    TrieNode* root = new TrieNode();

    insert(root, "cat");
    insert(root,"dog");
    insert(root, "mod");

    cout << boolalpha;
    cout << "search(\"cat\") → " << search(root, "cat") << endl;
    cout << "search(\"ca\")  → " << search(root, "ca") << endl;
    cout << "search(\"dog\") → " << search(root, "dog") << endl;
    cout << "search(\"do\")  → " << search(root, "do") << endl;

    cout << "startsWith(\"ca\")  → " << startsWith(root, "ca") << endl;
    cout << "startsWith(\"do\")  → " << startsWith(root, "do") << endl;
    cout << "startsWith(\"da\")  → " << startsWith(root, "da") << endl;

    return 0;
}

