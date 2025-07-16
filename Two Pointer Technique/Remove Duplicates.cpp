#include<iostream>
#include<vector>
using namespace std;

int findDuplicates(vector<int>& arr) {
    int left = 0;
    for (int right = 1; right < arr.size(); right++) {
        if (arr[left] != arr[right]) {
            left++;
            arr[left] = arr[right];
        }
    }
    cout << "Duplicates removed are: ";
    for (int i = 0; i < left - 1; i++) {
        cout << arr[i] << " ";
    }
    return left + 1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int  i = 0; i < n; i++) cin >> arr[i];
    int res = findDuplicates(arr);
    cout << "\n New length: " <<res << "\n";
    return 0;
}