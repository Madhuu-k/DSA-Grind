#include <iostream>
#include<unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, int> map;
    vector<int> arr = {1, 2, 3, 4, 5, 1};
    for (int i = 0; i < arr.size(); i++) {
        if (map.count(arr[i])) cout << "Duplicate Exists: " << arr[i] << endl;
        map[arr[i]]++;
    }
    return 0;
}