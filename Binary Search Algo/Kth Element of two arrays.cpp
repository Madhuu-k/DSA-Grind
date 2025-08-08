#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int KthElement(vector<int>& arrA, vector<int>& arrB, int k) {
    if (arrA.size() < arrB.size()) return KthElement(arrB, arrA, k);
    int n = arrA.size(), m = arrB.size();
    int low = max(0, k - m), high = min(k, n);
    while (low <= high) {
        int cutA = low + (high - low) / 2;
        int cutB = k - cutA;
        int l1 = (cutA == 0) ? INT_MIN : arrA[cutA - 1];
        int l2 = (cutB == 0) ? INT_MIN : arrB[cutB - 1];
        int r1 = (cutA == n) ? INT_MAX : arrA[cutA];
        int r2 = (cutB == m) ? INT_MAX : arrB[cutB];

        if (l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2) high = cutA - 1;
        else low = cutA + 1;
    }
    return -1;
}


int main() {
    vector<int> arrA = {2, 3, 6, 7, 9};
    vector<int> arrB = {1, 4, 8, 10};

    int k;
    cout << "Enter k: ";
    cin >> k;

    int result = KthElement(arrA, arrB, k);
    cout << k << "th element in merged sorted array is: " << result << endl;

    return 0;
}