#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {left + 1, right + 1};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cout << "Enter the target: ";
    cin >> target;
    vector<int> result = twoSum(arr, target);
    cout << "Target found at: ";
    for (int i : result) cout << i << endl;
    return 0;
}