#include<iostream>
#include <vector>
using namespace std;

class Treenode {
public:
    int val;
    Treenode* left;
    Treenode* right;

    Treenode(int val) {
        this -> val = val;
        left = right = nullptr;
    }
};

void InorderTraversal(Treenode* root) {
    if (root == nullptr) return;

    InorderTraversal(root -> left);;
    cout << root -> val << " ";
    InorderTraversal(root -> right);
}

void backTrack(Treenode* root, int targetSum, int currentSum, vector<int>& path, vector<vector<int>>& result) {
    if (root == nullptr) return;
    currentSum += root -> val;
    path.push_back(root -> val);

    if (!root -> val && !root -> right && currentSum == targetSum) result.push_back(path);

    backTrack(root -> left, targetSum, currentSum, path, result);
    backTrack(root -> right, targetSum, currentSum, path, result);
    path.pop_back();
}

vector<vector<int>> pathSum(Treenode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    backTrack(root, targetSum, 0, path, result);
    return result;
}



int main() {
    Treenode* root = new Treenode(1);
    root -> left = new Treenode(2);
    root -> right = new Treenode(3);
    root -> left -> left = new Treenode(4);
    root -> left -> right = new Treenode(5);
    root -> right -> right = new Treenode(6);
    cout << "Inorder traversal of constructed Tree: ";
    InorderTraversal(root);
    cout << "Enter target to find: ";
    int target;
    cin >> target;
    cout << "Total paths from source sto destination: ";
    for (auto&  num : pathSum(root, target)) {
        for (int n : num) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}