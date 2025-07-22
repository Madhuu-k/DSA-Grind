#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> map;
    map.insert({"Apple", 1});
    map.insert({"Banana", 2});
    map.insert({"Orange", 3});
    map.insert({"Cherry", 4});
    if (map.count("Apple")) cout << "Apple is there in the list" << endl;
    for (auto it : map) cout << it.first << ": " << it.second << endl;
    return 0;
 }