#include<iostream>
#include<vector>
using namespace std;

bool SumofSubsets(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (index == 0) return arr[0] == target;
    if (dp[index][target] != -1) return dp[index][target];

    bool notPick = SumofSubsets(index - 1, target, arr, dp);
    bool pick = false;
    if (arr[index] <= target) pick = SumofSubsets(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = pick || notPick;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    // Initialize dp array with -1
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    bool result = SumofSubsets(n - 1, target, arr, dp);

    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}