#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

void PermuatationWithDuplicates(vector<int>& arr, vector<vector<int>>& result, int index) {
    if (index == arr.size()) {
        result.push_back(arr);
        return;
    }

    unordered_set<int> seen;
    for (int i = index; i < arr.size(); i++) {
        if (seen.count(arr[i])) continue;
        swap(arr[index], arr[i]);
        PermuatationWithDuplicates(arr, result, index + 1);
        swap(arr[index], arr[i]);
    }
}

int main() {
    int n;
    cout << "Enter n value: ";
    cin >> n;
    vector<int> arr;
    vector<vector<int>> result;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    PermuatationWithDuplicates(arr, result, 0);
    for (const auto& perm : result) {
        for (int num : perm) cout << num << " ";
        cout << endl;
    }
    return 0;
}