#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& arr) {
    int maxReach = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + arr[i]);
    }
    return true;
}

int main() {
    vector<int> arr = {2,3,1,1,4};
    bool result = canJump(arr);
    cout << (result == 1 ? "True" : "False") << endl;
    return 0;
}