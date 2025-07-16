#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data  = val;
        next = nullptr;
    }
};

class queue {
public:
    node* front;
    node* rear;

    queue(){front = rear = nullptr; }

    void enqueue(int val) {
        node* temp = new node(val);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear -> next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow!\n";
            return;
        }
        node* temp = front;
        front = front -> next;

        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front -> data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void printQueue() {
        node* temp = front;
        if (temp == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(40);
    q.printQueue();
    cout << "Peek element: " << q.peek() << endl;
    q.dequeue();
    cout << "New Peek element: " << q.peek() << endl;
    q.dequeue();
    q.enqueue(30);
    cout << "Is empty: " << q.isEmpty() << endl;
    q.dequeue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
    return 0;
}