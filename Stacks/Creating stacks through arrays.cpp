#include<iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // ✅ Push operation
    void push(const int x) {
        if (top == MAX - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = x; // FIXED: pre-increment to store first at arr[0]
        cout << x << " pushed into stack" << endl;
    }

    // ✅ Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }

    // ✅ Peek operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << arr[top] << " is at the top of the stack" << endl;
    }

    // ✅ Display all elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.peek();     // 30
    st.display();  // 10 20 30
    st.pop();      // 30
    st.peek();     // 20
    st.display();  // 10 20

    return 0;
}
