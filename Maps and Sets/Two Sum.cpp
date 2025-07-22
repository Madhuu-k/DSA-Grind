#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, int> m;
    int key = 9;
    int targetReach = 0;
    vector<int> arr = {2, 7, 11, 15};
    for (int i = 0; i < arr.size(); i++) {
        int targetSum = key - arr[i];
        if (m.count(targetSum)) cout << "Sum Exists: " << endl;
        m[arr[i]] = i;
    }
    return 0;
}
