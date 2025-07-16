#include<iostream>
#include<vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (n == 0) {
        if (wt[0] <= W) return val[0];
        else return 0;
    }
    if (dp[n][W] != -1) return dp[n][W];

    int notPick = knapsack(n - 1, W, wt, val, dp);
    int pick = INT_MIN;
    if (wt[n] <= W) pick = val[n] + knapsack(n - 1, W - wt[n], wt, val, dp);
    return dp[n][W] =  max(pick, notPick);
}

int main() {
    int n;
    cout << "Enter total elements: ";
    cin >> n;
    vector<int> wt(n);
    vector<int> val(n);
    int W;
    cout << "Enter capacity: ";
    cin >> W;
    cout << "Enter weight matrix: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter value matrix: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "Maximum is: "  << knapsack(n - 1, W, wt, val, dp);
    return 0;
}