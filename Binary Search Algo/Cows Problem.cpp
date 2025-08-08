#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool canPlaceCows(vector<int>& nums, int k, int minDist) {
    int count = 0;
    int lastPos = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] + lastPos >= minDist) {
            count++;
            lastPos = nums[i];
        }
        if (count == k) return true;
    }
    return false;
}

int main() {
    vector<int> aggressiveCows = {10, 20, 30, 60, 90, 110};
    sort(aggressiveCows.begin(), aggressiveCows.end());
    int low = 1, high = aggressiveCows.back() - aggressiveCows[0];
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(aggressiveCows, 2, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans << endl;
    return 0;
}