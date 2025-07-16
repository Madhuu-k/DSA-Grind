#include<iostream>
using namespace std;

int fact(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int result = fact(n);
    cout << "Fibonacci Series result is " << result << endl;
    return 0;
}