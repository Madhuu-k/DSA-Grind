#include<iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear;
    int size;
public:
    CircularQueue(int capacity) {
        size = capacity;
        front = 0;
        rear = -1;
        arr = new int[size];
    }

    bool isFull() {
        return (front == 0 && rear == size - 1 || ((rear + 1) % size == front));
    }

    bool isEmpty() { return front == -1; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }

        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % size;

        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }
        if (front == rear) front = rear = - 1;
        else front = (front + 1) % size;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Is queue empty: " << q.isEmpty() << endl;
    cout << "Queue elements: " << endl;
    q.printQueue();
    q.enqueue(70);
    cout << "peek: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "New peek: " << q.peek() << endl;
    q.enqueue(10);
    cout << "Queue elements: " << endl;
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;

 }