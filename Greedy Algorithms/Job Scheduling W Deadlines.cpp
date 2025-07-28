#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

int jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comp);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) maxDeadline = max(maxDeadline, arr[i].deadline);
    vector<int> slot(maxDeadline + 1, -1); // [-1, -1, -1,...., -1]
    int totaProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totaProfit += arr[i].profit;
                break;
            }
        }
    }
    return totaProfit;
}

int main() {
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Profit: " << jobScheduling(arr, n) << endl;
    return 0;
}