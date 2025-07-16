#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // IF THE FIRST PATH ITSELF IS BLOCKED
    if (obstacleGrid[0][0] == 1) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }
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
    cout << "Enter grid size (m rows, n columns): ";
    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    cout << "Enter the grid (0 for free, 1 for obstacle):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    int result = uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
