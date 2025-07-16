#include<iostream>
#include<vector>
using namespace std;

bool SumofSubsets(int index, int target, vector<int>& arr) {
    if (target == 0) return true;
    if (index == 0) return arr[0] == target;
    bool notPick = SumofSubsets(index - 1, target, arr);
    bool pick = false;
    if (arr[index] <= target) pick = SumofSubsets(index - 1, target - arr[index], arr);
    return pick || notPick;
}

int main() {
    int n;
    vector<int> arr;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter your array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target: ";
    int target;
    cin >> target;
    bool result = SumofSubsets(n - 1, target, arr);
    if (result) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}