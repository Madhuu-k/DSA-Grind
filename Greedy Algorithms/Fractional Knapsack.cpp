#include<iostream>
#include<vector>
#include<algorithm>
#include <complex.h>
using namespace std;

struct Item {
    int weight, value;
};

bool comp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, int arr[], int n) {
    sort(arr, arr + n, comp);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else {
            totalValue += arr[i].value * ((double)W/ arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = std::size(arr);

    cout << "Max value = " << fractionalKnapsack(W, arr, n) << endl;
    return 0;
}