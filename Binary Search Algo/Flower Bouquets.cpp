#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int>& blooms, int numBouquetsNeeded, int kBloomedFlowers, int day) {
    int count = 0, bouquets = 0;
    for (int i = 0; i < blooms.size(); i++) {
        if (blooms[i] <= day) {
            count++;
            if (count == kBloomedFlowers) {
                count = 0;
                bouquets++;
            }
        }
        else count++;
    }
    return bouquets >= numBouquetsNeeded;
}


int minDays(vector<int>& bloomDay, int m, int k) {
    long long totalFlowers = (long long)m * k;
    if (bloomDay.size() < totalFlowers)
        return -1;  // not enough flowers

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(bloomDay, m, k, mid)) {
            ans = mid;          // try to find smaller valid day
            high = mid - 1;
        } else {
            low = mid + 1;      // not enough bloomed, try later
        }
    }
    return ans;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int result = minDays(bloomDay, m, k);
    cout << "Minimum day to make bouquets = " << result << endl;
    return 0;
}