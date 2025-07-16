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

bool isMirror(Treenode* t1, Treenode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;

    return (t1 -> val == t2 -> val) && isMirror(t1 -> left, t2 -> right) && isMirror(t1 -> right, t2 -> left);
}

bool isSymmetric(Treenode* root) {
    if (root == nullptr) return true;
    return isMirror(root -> left, root -> right);
}

int main() {
    Treenode* root = new Treenode(1);
    root -> left = new Treenode(2);
    root -> right = new Treenode(3);
    root -> left -> left = new Treenode(4);
    root -> left -> right = new Treenode(5);
    root -> right -> right = new Treenode(6);
    cout << "Is the tree a mirror?: " << isSymmetric(root) << endl;
    cout << "Inorder traversal of constructed Tree: ";
    InorderTraversal(root);
    cout << endl;
    return 0;
}