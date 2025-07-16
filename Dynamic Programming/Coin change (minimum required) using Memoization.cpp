#include<iostream>
#include<vector>
using namespace std;

int countMinWays(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (index == 0) {
        if (target % coins[0] == 0) return target / coins[0];
        else return 1e9;
    }
    if (target == 0) return 0;
    if (dp[index][target] != -1) return dp[index][target];

    int notPick = countMinWays(index, target, coins, dp);
    int pick = 1e9;
    if (coins[index] <= target) pick = 1 + countMinWays(index, target, coins, dp);
    return dp[index][target] = min(pick, notPick);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> coins[i];
    int target;
    cout << "Enter target: ";
    cin >> target;
    vector<vector<int>> dp(n,vector<int>(target + 1, -1));
    int result = countMinWays(n - 1, target, coins, dp);
    cout << "Total number of minimum ways: " << result << endl;
    return 0;
}
