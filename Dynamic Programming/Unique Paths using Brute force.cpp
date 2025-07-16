#include<iostream>
#include<vector>
using namespace std;

int getUniqueWays(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    int leftWay = getUniqueWays(i - 1, j);
    int downWay = getUniqueWays(i, j - 1);
    return leftWay + downWay;
}

int main() {
    int m, n;
    cout << "Enter grid dimensions (m rows, n columns): ";
    cin >> m >> n;

    // m x n grid => destination is at (m-1, n-1)
    int result = getUniqueWays(m - 1, n - 1);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
7