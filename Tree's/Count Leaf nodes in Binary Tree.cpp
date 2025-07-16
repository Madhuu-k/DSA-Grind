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

int height(Treenode* root){
    if (root == nullptr) return 0;
    int left = height(root -> left);
    int right = height(root -> right);
    return 1 + max(left, right);
}

int countLeafNodes(Treenode* root) {
    if (root == nullptr) return 0;
    if (root -> left == nullptr && root -> right == nullptr) return 1;
    return countLeafNodes(root -> left) + countLeafNodes(root -> right);
}

int main() {
    Treenode* root = new Treenode(1);
    root -> left = new Treenode(2);
    root -> right = new Treenode(3);
    root -> left -> left = new Treenode(4);
    root -> left -> right = new Treenode(5);
    root -> right -> right = new Treenode(6);
    cout << "Total Leaf nodes: " << countLeafNodes(root) << endl;
    cout << "Inorder traversal of constructed Tree: ";
    InorderTraversal(root);
    cout << endl;
    return 0;
}