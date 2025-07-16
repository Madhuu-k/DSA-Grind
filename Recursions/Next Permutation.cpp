#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;

    // find first least number
    while (i >= 0 && arr[i] >= arr[i + 1]) i--; // loop until you find

    if (i >= 0) {
        int j = n - 1; // starts from right
        if (arr[j] <= arr[i]) j--;
        swap(arr[i], arr[j]);
    }

    reverse(arr.begin() + i + 1, arr.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    nextPermutation(arr);

    cout << "Next Permutation: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;

}