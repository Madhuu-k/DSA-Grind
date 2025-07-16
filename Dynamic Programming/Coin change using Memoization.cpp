#include<iostream>
#include<vector>
using namespace std;

int countWays(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (target == 0) return 1;
    if (index == 0) return (target % coins[0] == 0)? 1 : 0;
    if (dp[index][target] != -1) return dp[index][target];

    int notPick = countWays(index - 1, target, coins, dp);
    int pick = 0;
    if (coins[index] <= target) pick = countWays(index, target - coins[index], coins, dp);
    return pick + notPick;
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
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int result = countWays(n - 1, target, coins, dp);;
    cout << "Total number of ways: " << result << endl;
    return 0;
}