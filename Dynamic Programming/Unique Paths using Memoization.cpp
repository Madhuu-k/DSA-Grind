#include<iostream>
#include<vector>
using namespace std;

int countPaths(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int leftWay = countPaths(i - 1, j, dp);
    int downWay = countPaths(i, j - 1, dp);
    return dp[i][j] = leftWay + downWay;
}

int main() {
    int m, n;
    cout << "Enter grid dimensions (m rows, n columns): ";
    cin >> m >> n;

    vector<vector<int>> dp(m, vector<int>(n + 1, -1));
    int result = countPaths(m - 1, n - 1, dp);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
