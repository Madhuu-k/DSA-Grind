#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int minMeetings(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= minHeap.top()) minHeap.pop();
        minHeap.push(intervals[i][1]);
    }
    return minHeap.size();
}

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter start and end times (space separated):\n";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = minMeetings(intervals);
    cout << "Minimum number of rooms required: " << result << endl;

    return 0;
}