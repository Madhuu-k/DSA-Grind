#include <functional>
#include<iostream>
using namespace std;

class queue {
private:
    int* arr;
    int capacity, front, rear;
public:
    queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    void enqueue(int element) {
        if (rear == capacity - 1) {
            cout << "Queue overflow!";
            return;
        }
        arr[++rear] = element;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue underflow!";
            return;
        }
        front++;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};

int main() {
    queue* q = new queue(10);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(50);
    cout << "Peek element: " << q->peek() << endl;
    q->dequeue();
    q->dequeue();
    cout << "Peek element: " << q->peek() << endl;
    q->dequeue();
    q->dequeue();
    q->dequeue();
    cout << endl;
    cout << "Is empty: " << q->isEmpty() << endl;
    return 0;
}