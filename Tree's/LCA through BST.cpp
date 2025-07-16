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
    if (p1 -> val < root -> val && p2 -> val < root -> val) return LCA(root -> left, p1, p2);
    else if (p1 -> val > root -> val && p2 -> val > root -> val) return LCA(root -> right, p1 , p2);
    else return root;
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