#include<iostream>
#include<vector>
using namespace std;

void findSubsets(vector<int>& nums, vector<int>& current ,int index) {
    if (index == nums.size()) {
        cout << "[";
        for (int num : current) cout << num << " ";
        cout << "]\n";
        return;
    }

    //INCLUSION
    current.push_back(nums[index]);
    findSubsets(nums, current, index + 1);

    //EXCLUSION
    current.pop_back();
    findSubsets(nums, current, index + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> current;
    findSubsets(nums, current, 0);
    return 0;
}