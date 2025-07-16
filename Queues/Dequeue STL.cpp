#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(40);

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    dq.pop_back();
    dq.pop_front();
    cout << "after popping: ";
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    cout << "Size: " << dq.size() << endl;
    cout << "isEmpty: " << dq.empty() << endl;
    return 0;
}
