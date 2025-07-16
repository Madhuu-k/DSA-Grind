#include<iostream>
#include<vector>
using namespace std;

bool SumofSubsets(int index, int target, vector<int>& arr) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= target) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            bool notPick = dp[i - 1][t];
            bool pick = false;
            if (arr[i] <= t) pick = dp[i - 1][t - arr[i]];
            dp[i][t] = pick || notPick;
        }
    }
    return dp[n - 1][target];
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int targetSubset;
    cout << "Enter target subset: ";
    cin >> targetSubset;
    bool result = SumofSubsets(n - 1, targetSubset, arr);
    if (result) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}