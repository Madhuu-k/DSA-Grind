#include<iostream>
#include<algorithm>
using namespace std;

int minimumPlatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0;
    int platforms = 1, result = 1;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        }
        else {
            platforms--;
            j++;
        }
        result = max(result, platforms);
    }
    return result;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200,1120,1130,1900,2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum platforms: " << minimumPlatforms(arr, dep, n);
    return 0;
}