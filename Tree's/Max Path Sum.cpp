#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxSum = INT_MIN;

int maxPathDown(TreeNode* node) {
    if (!node) return 0;

    int left = max(0, maxPathDown(node->left));   // Ignore negative paths
    int right = max(0, maxPathDown(node->right));

    // Max path through this node
    maxSum = max(maxSum, left + right + node->val);

    return node->val + max(left, right);  // For parent use
}

int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    maxPathDown(root);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int result = maxPathSum(root);
    cout << "Max Path Sum = " << result << endl;

    return 0;
}
