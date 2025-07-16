#include<iostream>
#include<algorithm>
using namespace std;

string nextPermutation(string str) {
    int n = str.size();
    int i = n - 2;

    while (i >= 0 && str[i] >= str[i + 1]) i--;

    if (i < 0) return "no answer!!";

    int j = n - 1;
    while (str[j] <= str[i]) j--;
    swap(str[i], str[j]);
    reverse(str.begin() + 1 + i, str.end());

    return str;
}

int main() {
    cout << "Enter string: ";
    string str;
    cin >> str;

    string res = nextPermutation(str);

    cout << "Next Permutation: ";
    cout << res;
    return 0;

}
