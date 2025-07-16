#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = nullptr;

node* createNode() {
    node* newnode = new node();
    cout << "Enter data: ";
    cin >> newnode -> data;
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

void insertAtBeginning(int val) {
    node* newnode = new node();
    newnode -> data = val;
    newnode -> next = start;
    start = newnode;
}

void insertAtEnd(int val) {
    node* newnode = new node();
    newnode -> data = val;
    newnode -> next = nullptr;

    if (start == nullptr) {
        start = newnode;
        return;
    }

    node* temp = start;
    while (temp -> next != nullptr) temp = temp -> next;
    temp -> next = newnode;
}

void insertAtPosition(int pos, int val) {
    if (pos <= 0) {
        cout << "Invalid position!!";
        return;
    }

    node* newnode = new node();
    newnode -> data = val;
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }

    node* temp = start;
    for (int i = 1; i < pos && temp != nullptr; i++) temp = temp -> next;

    if (temp == nullptr) {
        cout << "Invalid bound!!";
        return;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void displayList(node* start) {
    node* temp = start;
    while (temp -> next != nullptr) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << temp -> data << "->NULL" << endl;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    createList(n);
    cout << "\nBefore Operations: ";
    displayList(start);
    cout << "\n";
    int a, b, c, pos;
    cout << "Enter element to be inserted first: ";
    cin >> a;
    insertAtBeginning(a);
    cout << "Enter element to be inserted last : ";
    cin >> b;
    insertAtEnd(b);
    cout << "Enter element to be inserted position: ";
    cin >> pos;
    cout << "Enter the value: ";
    cin >> c;
    insertAtPosition(pos, c);
    cout << "\nAfter Operations: ";
    displayList(start);


}