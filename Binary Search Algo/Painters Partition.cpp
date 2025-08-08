#include<iostream>
#include<algorithm>
#include <numeric>
#include<vector>
using namespace std;

bool canPaint(vector<int>& boards, int k, int maxLen) {
    int painters = 1, curr = 0;
    for (int len : boards) {
        if (len + curr > maxLen) {
            painters++;
            curr = len;
            if (painters > k) return false;
        }
        else curr += len;
    }
    return true;
}

int minTime(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPaint(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << "Time Taken: " <<minTime(boards, k) << "mins" << endl;
    return 0;
}