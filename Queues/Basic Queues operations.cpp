#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.front() << endl;
    q.pop();
    cout << "New front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is empty? : " << q.empty() << endl;
    return 0;
}