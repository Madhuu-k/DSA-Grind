#include<iostream>
#include<vector>
using namespace std;

int minCountWays(int index, int target, vector<int>& coins) {
    if (target == 0) return 1;
    if (index == 0) {
        if(target % coins[0] == 0) return target / coins[0];
        else return 1e9;
    }

    int notPick = minCountWays(index - 1, target, coins);
    int pick = 1e9;
    if (coins[index] <= target) pick = 1 + minCountWays(index - 1, target - coins[index], coins);
    return min(pick, notPick);
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
    vector<vector<int>> dp(n, vector<int>(target - 1, -1));
    int result = minCountWays(n - 1, target, coins);
    cout << "Total number of minimum ways: " << result << endl;
    return 0;
}
