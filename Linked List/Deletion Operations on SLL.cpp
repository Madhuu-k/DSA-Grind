#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = nullptr;

node* createNode() {
    node* newnode = new node();
    cout << "Enter value: ";
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

void deleteAtBeginning() {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = start;
    start = start -> next;
    delete temp;
}

void deleteAtEnd() {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (start -> next == nullptr) {
        delete start;
        start = nullptr;
        return;
    }

    node* temp = start;
    while (temp -> next -> next != nullptr) temp = temp -> next;
    delete temp -> next;
    temp -> next = nullptr;
}

void deleteAtPosition(int pos) {
    if (pos <= 0) {
        cout << "Position cannot be less than 0";
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    node *temp = start;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) temp = temp -> next;
    if (temp == nullptr || temp -> next == nullptr) {
        cout << "Position out of bounds";
        return;
    }

    node* delNode = temp -> next;
    temp -> next = delNode -> next;
    delete delNode;
}

void displayList() {
    node* temp = start;
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
    cout << "List before deletion: ";
    displayList();
    cout << "\n";
    int pos;
    deleteAtBeginning();
    deleteAtEnd();
    cout << "Enter position to delete: ";
    cin >> pos;
    deleteAtPosition(pos);
    cout << "\nAfter deletion operations: ";
    displayList();
    return 0;
}