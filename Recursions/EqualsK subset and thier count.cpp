#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

void FindSumK(vector<int>& nums, vector<int>& current, int index, int target, int currentSum, int& count) {
    if (index == nums.size()) {
        if (currentSum == target) {
            count++;
            cout << "[";
            for (int num : current) cout << num << " ";
            cout << "]";
        }
        return;
    }

    //INCLUSION
    current.push_back(nums[index]);
    FindSumK(nums, current, index + 1, target, currentSum + nums[index], count);

    //EXCLUSION
    current.pop_back();
    FindSumK(nums, current, index + 1, target, currentSum, count);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> current;
    int target;
    cout << "Enter target: ";
    cin >> target;
    int count = 0;
    FindSumK(nums, current, 0, target, 0, count);
    cout << "\nTotal number of elements: " << count << endl;
    return 0;
}
