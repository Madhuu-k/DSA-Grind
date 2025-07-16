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

node* middleNode(node* start) {
    node* slow = start;
    node* fast = start;
    while (fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    createList(n);
    cout << "\nThe list is: ";
    displayList();
    cout << "\n";
    start = middleNode(start);
    cout << "The middle node is: " << start -> data << endl;
    return 0;
}