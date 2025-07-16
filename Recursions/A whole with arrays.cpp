#include <iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr, int n) {
    if (n == 0 || n == 1) return true;
    if (arr[n-1] > arr[n]) return false;
    return isSorted(arr, n - 1);
}

int sumOfArray(vector<int>& arr, int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

void printElements(vector<int>& arr, int n) {
    if (n == 0) return;
    printElements(arr, n - 1);
    cout << arr[n - 1] << " ";
}

int findMax(vector<int>& arr, int n) {
    if (n == 1) return arr[0];
    return max(arr[n - 1], findMax(arr, n - 1));
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    printElements(arr, n);
    cout << endl;
    bool res = isSorted(arr, n);
    if (res) cout << "The array is sorted." << endl;
    else cout << "The array is not sorted." << endl;
    int sum = sumOfArray(arr, n);
    cout << "Sum of array: " << sum << endl;
    int max = findMax(arr, n);
    cout << "Maximum of array: " << max << endl;
    return 0;
}