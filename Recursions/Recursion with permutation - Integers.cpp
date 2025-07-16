#include<iostream>
#include<vector>
using namespace std;

void Permute(vector<int>& arr, vector<vector<int>>& result, int index) {
    if (index == arr.size()) {
        result.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        Permute(arr, result, index + 1);
        swap(arr[index], arr[i]);
    }
}

int main() {
    vector<int> arr;
    cout << "Enter total elements: ";
    int n;
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> result;
    Permute(arr, result, 0);
    return 0;
}