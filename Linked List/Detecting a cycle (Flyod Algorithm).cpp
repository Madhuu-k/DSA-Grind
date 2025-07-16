//
// Created by MADHU on 20-06-2025.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = nullptr;

node* createNode() {
    node* newnode = new node();
    cout << "Enter data:" << " ";
    cin >> newnode -> data;
    newnode -> next = nullptr;
    return newnode;
}

void createList(int n) {
    node *newnode, *temp;
    for (int i = 0; i < n; i++) {
        newnode = createNode();
        if (start == nullptr) start = newnode;
        else {
            temp = start;
            while (temp -> next != nullptr) temp = temp -> next;
            temp -> next = newnode;
        }
    }
}

void displayList() {
    node* temp = start;
    while (temp != nullptr) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

bool isCycle() {
    node* slow = start;
    node* fast = start;
    while (fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    createList(n);
    cout << "\nThe list is: ";
    displayList();
    cout << "\n";
    bool result = isCycle();
    cout << "Does the list contain a cycle?: " << result << endl;
    return 0;
}