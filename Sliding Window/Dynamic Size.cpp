#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMinSubArraySum(int target, vector<int> &arr) {
    int left = 0, n = arr.size(), sum = 0, minLen = INT_MAX;
    for (int right = 0; right < n; right++){
        sum += arr[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int targetValue;
    cout << "Enter the target value: ";
    cin >> targetValue;
    int result = findMinSubArraySum(targetValue, arr);
    cout << result << endl;
    return 0;
}