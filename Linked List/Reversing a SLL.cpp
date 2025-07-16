#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = nullptr;

node* getNode() {
    node* newnode = new node();
    cout << "Enter data: ";
    cin >> newnode -> data;
    newnode -> next = nullptr;
    return newnode;
}

void createList(int n) {
    node *newnode, *temp;
    for (int i = 0; i < n; i++){
        newnode = getNode();
        if (start == nullptr) start = newnode;
        else {
        temp = start;
        while (temp -> next != nullptr) temp = temp -> next;
        temp -> next = newnode;
    }
    }
}

node* reverseList() {
    node* prev = nullptr;
    node* temp = start;
    while (temp != nullptr) {
        node* nextNode = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}

void displayList() {
    node *temp = start;
    while (temp -> next != nullptr) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << temp -> data << "->NULL" << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    createList(n);
    cout << "\nBefor Reversing the list: ";
    displayList();
    cout << "\nAfter Reversing the list: ";
    start = reverseList();
    displayList();
    return 0;
}