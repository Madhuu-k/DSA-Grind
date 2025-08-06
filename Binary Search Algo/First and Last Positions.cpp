#include<iostream>
#include<vector>
using namespace std;

int firstAppearance(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int lastAppearance(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid -1;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 5, 7, 7, 7, 7, 9, 10};
    int target = 7;
    int result[] = {firstAppearance(nums, target), lastAppearance(nums, target)};
    cout << "Appearance: " << result << endl;
}