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

    cout << root -> val << " ";
    InorderTraversal(root -> left);;
    InorderTraversal(root -> right);
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
    cout << endl;
    return 0;
}