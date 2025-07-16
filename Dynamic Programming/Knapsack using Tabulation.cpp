#include<iostream>
#include<vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int w = wt[0]; w < W; w++) dp[0][w] = val[0]; // make first row zeros
    for (int i = 1; i < n; i++) {
        for (int w = 0; w < W; w++) {
            int notPick = dp[i - 1][w];
            int pick = INT_MIN;
            if (wt[i] <= w) pick = val[i] + dp[i - 1][w - wt[i]];
            dp[i][w] = max(pick, notPick);
        }
    }
    return dp[n - 1][W];
}


int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    int result = knapsack(n, W, wt, val);
    cout << "Maximum value: " << result << endl;

    return 0;
}