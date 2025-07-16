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

Treenode* LCA(Treenode* root, Treenode* p1, Treenode* p2) {
    if (!root || root == p1 || root == p2) return root;

    Treenode* left = LCA(root -> left, p1, p2);
    Treenode* right = LCA(root -> right, p1, p2);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    Treenode* root = new Treenode(1);
    root -> left = new Treenode(2);
    root -> right = new Treenode(3);
    root -> left -> left = new Treenode(1);
    root -> left -> right = new Treenode(5);
    root -> right -> right = new Treenode(6);
    cout << "Inorder traversal of constructed Tree: ";
    InorderTraversal(root);
    cout << "\nLeast Common Ancestor: " << LCA(root, root -> left, root -> right);
    cout << endl;
    return 0;
}