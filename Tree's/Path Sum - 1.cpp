#include<iostream>
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

bool backTrack(Treenode* root, int currentsum, int targetSum) {
    if (root == nullptr) return false;
    currentsum += root -> val;
    if (!root -> left && !root -> right) return currentsum == targetSum;

    bool left = backTrack(root -> left, currentsum, targetSum);
    bool right = backTrack(root -> right, currentsum, targetSum);

    return left || right;
}

bool hasSumPath(Treenode* root, int targetSum) {
    if (root == nullptr) return false;
    return backTrack(root, 0, targetSum);
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
    cout << "\nDoes the path from root exist?: " << hasSumPath(root, target);
    cout << endl;
    return 0;
}