#include <iostream>
using namespace std;

class Deque {
private:
    int size;
    int front, rear;
    int* arr;
public:
    Deque(int cap) {
        size = cap;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isFull() { return (front == (rear + 1) % size); }
    bool isEmpty() { return front == -1; }

    void push_front(int x) {
        if (isFull()) {
            cout << "Deque overflow at front\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else front = (front - 1 + size) % size;
        arr[front] = x;
    }

    void push_back(int x) {
        if (isFull()) {
            cout << "Deque overlow at rear\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Deque underflow at front\n";
            return;
        }
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "Deque underflow at back\n";
            return;
        }
        if (front == rear) front = rear = -1;
        else rear = (rear - 1 + size) % size;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque Empty!\n";
            return -1;
        }
        return arr[front];
    }

    int getRare() {
        if (isEmpty()) {
            cout << "Deque Empty!\n";
            return -1;
        }
        return arr[rear];
    }

    void printDeque() {
        if (isEmpty()) {
            cout << "Deque empty can't print\n";
            return;
        }
        int i = front;
        while(true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(8);
    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);
    cout << "Current Deque: \n";
    dq.printDeque();
    dq.pop_front();
    dq.pop_back();
    cout << "Deque after poping: \n";
    dq.printDeque();
    cout << "Front: " << dq.getFront() << "\n";
    cout << "Back: " << dq.getRare() << "\n";
    dq.pop_back();
    dq.pop_back();
    dq.pop_front();
    dq.pop_front();
    cout << "After other popping's: \n";
    dq.printDeque();
    return 0;
}