#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode() {
    Node* newNode = new Node();
    cout << "Enter value: ";
    cin >> newNode -> data;
    return newNode;
}

void createList(Node* &start, int n) {
    Node *newNode, *temp;
    for (int i = 0; i < n; i++) {
        newNode = createNode();
        if (start == nullptr) start = newNode;
        else {
            temp = start;
            while (temp -> next != nullptr) temp = temp -> next;
            temp -> next = newNode;
        }
    }
}

void displayList(Node* start) {
    Node* temp = start;
    while (temp -> next != nullptr) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << temp -> data << "->NULL" << endl;
}

int main() {
    int n;
    Node* start = nullptr;
    cout << "Enter total data: ";
    cin >> n;
    createList(start, n);
    cout << "\nLinked List created: \n";
    displayList(start);
    return 0;
}