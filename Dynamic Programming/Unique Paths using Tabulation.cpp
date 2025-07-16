#include<iostream>
#include<vector>
using namespace std;

int countPaths(int m, int n) {
    vector<vector<int>> dp(m, vector(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = 1;
            else {
                int leftWay = (i > 0)? dp[i - 1][j] : 0;
                int downWay = (j > 0)? dp[i][j - 1] : 0;
                dp[i][j] = leftWay + downWay;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter grid dimensions (m rows, n columns): ";
    cin >> m >> n;

    vector<vector<int>> dp(m, vector<int>(n + 1, -1));
    int result = countPaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
