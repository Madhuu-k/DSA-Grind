#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> map;
    map[0] = 0;
    map[1] = 1;
    map[2] = 2;
    map[3] = 3;
    map[1] = 6; // Update the value from 1 to 6
    for (auto i : map) cout <<i.first << " -> " << i.second << endl;
    return 0;
}