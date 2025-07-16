#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void permuteDuplicates(vector<int>& arr, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
    if (current.size() == arr.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (used[i]) continue;

        if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        current.push_back(arr[i]);
        permuteDuplicates(arr, current, used, result);
        used[i] = false;
        current.pop_back();
    }
}

int main() {
    int n;
    cout << "Enter total elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<vector<int >> result;
    vector<int> current;
    vector<bool> used(n , false);
    permuteDuplicates(arr, current, used, result);
    for (const auto& perm : result) {
        for (int num : perm) cout << num << " ";
        cout << endl;
    }
    return 0;
}