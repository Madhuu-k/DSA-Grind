#include<iostream>
#include<vector>
using namespace std;

int countMinWays(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0) dp[0][t] = t / coins[0];
        else dp[0][t] = 1e9;
    }

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int notPick = dp[i - 1][t];
            int pick = 1e9;
            if (coins[i] <= t) pick = 1 + dp[i][t - coins[i]];
            dp[i][t] = min(pick ,notPick);
        }
    }

    int result = dp[n - 1][target];
    return (result >= 1e9)? -1 : result;
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
    int result = countMinWays(coins, target);
    cout << "Total number of minimum ways: " << result << endl;
    return 0;
}
