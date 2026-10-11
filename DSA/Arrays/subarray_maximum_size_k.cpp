#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;

        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
    return 0;
}