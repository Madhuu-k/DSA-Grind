#include <iostream>
using namespace std;

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // size of left subarray
    int n2 = r - m;     // size of right subarray

    int* left = new int[n1];
    int* right = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge temp arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements if any
    while (i < n1) {
        arr[k] = left[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++; k++;
    }

    delete[] left;
    delete[] right;
}

// Recursive merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Find the middle point
        mergeSort(arr, l, m);    // Sort first half
        mergeSort(arr, m + 1, r);// Sort second half
        merge(arr, l, m, r);     // Merge the sorted halves
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = std::size(arr);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
