#include<iostream>
#include<vector>
using namespace std;

int countWays(vector<int>& coins, int target, int index) {
    if (target == 0) return 1;
    if (index == 0) return(target % coins[0] == 0)? 1 : 0;

    int notPick = countWays(coins, target, index - 1);
    int pick = 0;
    if (coins[index] <= target) pick = countWays(coins, target - coins[index], index - 1);
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
    int result = countWays(coins, target, n - 1);
    cout << "Total number of ways: " << result << endl;
    return 0;
}