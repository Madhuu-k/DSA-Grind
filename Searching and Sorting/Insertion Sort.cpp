#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    InsertionSort(arr, n);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}