#include<iostream>
#include<string>
#include<vector>
using namespace std;

string KthPermutation(int n, int k) {
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact *= i;
    }
    k--;
    string result = "";

    for (int i = 0; i < n; i++) {
        fact = fact / (n - i);
        int index = k / fact;
        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
        k = k % fact;
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter N value: ";
    cin >> n;
    cout << "Enter Kth value: ";
    cin >> k;
    string result = KthPermutation(n, k);
    cout << result << endl;
    return 0;
}