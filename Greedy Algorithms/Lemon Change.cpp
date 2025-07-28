#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) five++;
        if (bill == 10) {
            if (five == 0) return false;
            ten++;
            five--;
        }
        if (bill == 20) {
            if (five > 3) five -= 3;
            else if (five == 1 && ten == 1) {
                five--;
                ten--;
            }
            else return false;

        }
    }
    return true;
}

int main() {
    vector<int> bills =
}