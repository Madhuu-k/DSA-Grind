#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& balls, int m, int minDist) {
    int count = 1;
    int lastPos = balls[0];
    for (int i = 1; i < balls.size(); i++) {
        if (balls[i] - lastPos >= minDist) {
            count++;
            lastPos = balls[i];
        }

        if (count == m) return true;
    }
    return false;
}

int magneticBalls(vector<int>& balls, int m){
    sort(balls.begin(), balls.end());
    int low = 1;
    int high = balls.back() - balls[0];
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(balls, m, mid)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int main() {
    vector<int> balls = {1, 2, 3, 4, 7};
    int m = 3;
    cout << "Min Distance: " << magneticBalls(balls, m) << endl;
    return 0;
}