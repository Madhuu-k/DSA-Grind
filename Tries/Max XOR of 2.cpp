#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Trie {
    Trie* next[2];
    Trie() : next{nullptr, nullptr} {}
};

void insert(Trie* root, int x) {
    Trie* node = root;
    for (int b = 31; b >= 0; b--) {
        int bit = (x >> b) & 1;
        if (!node -> next[bit]) node -> next[bit] = new Trie();
        node = node -> next[bit];
    }
}

int bestXOR(Trie* root, int x) {
    Trie* node = root;
    int ans = 0;
    for (int b = 31; b >= 0; b--) {
        int bit = (x >> b) & 1;
        int want = bit ^ 1;
        if (node -> next[want]) {
            ans |= (1 << b);
            node = node -> next[want];
        }
        else node = node -> next[bit];
    }
    return ans;
}

int findMax(vector<int>& nums) {
    Trie* root = new Trie();
    int best = 0;
    for (int i = 0; i < nums.size(); i++) {
        best = max(best, bestXOR(root, nums[i]));
        insert(root, nums[i]);
    }
    return best;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};  // Example input
    cout << "Maximum XOR of any two numbers: " << findMax(nums) << endl;
    return 0;
}
