//
// Created by MADHU on 22-07-2025.
//
#include<iostream>
using namespace std;

struct Treenode {
    int val;
    Treenode *left, *right;
    Treenode(int x): val(x), left(nullptr), right(nullptr) {}
};

Treenode* insert(Treenode* root, int key) {
    if (root == nullptr) return new Treenode(key);
    if (key < root -> val) root -> left = insert(root -> left, key);
    else if (key > root -> val) root -> right = insert(root -> right, key);
    return root;
}

bool search(Treenode* root, int key) {
    if (root == nullptr) return false;
    if (key == root -> val) return true;
    if (key < root -> val) return search(root -> left, key);
    else return search(root -> right, key);
}

// Delete Functions

Treenode* findMin(Treenode* root) {
    while (root -> left != nullptr) root = root -> left;
    return root;
}

Treenode* deleteNode(Treenode* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root -> val) root -> left = deleteNode(root -> left, key);
    else if (key > root -> val) root -> right = deleteNode(root -> right, key);
    else {
        if (root -> left == nullptr) {
            Treenode* temp = root -> right;
            delete root;
            return temp;
        }

        else if (root -> right == nullptr) {
            Treenode* temp = root -> left;
            delete root;
            return temp;
        }

        Treenode* temp = findMin(root -> right);
        root -> val = temp -> val;
        root -> right = deleteNode(root -> right, temp -> val);
    }
    return root;
}

void inorder(Treenode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

Treenode* first = nullptr;

int main() {
    Treenode* root = nullptr;

    // Insert elements
    int keys[] = {10, 5, 15, 3, 7, 12, 18};
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "Inorder Traversal (Initial BST): ";
    inorder(root);
    cout << endl;

    // Search for an element
    int target = 7;
    cout << "Searching for " << target << ": ";
    cout << (search(root, target) ? "Found ✅" : "Not Found ❌") << endl;

    // Delete a node
    int del = 10;
    root = deleteNode(root, del);
    cout << "After deleting " << del << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
