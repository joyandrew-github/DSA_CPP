
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {3, 0, 1};

    int n = arr.size();
    int expectedSum = n * (n + 1) / 2;

    int actualSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        actualSum += arr[i];
    }

    cout << expectedSum - actualSum;

    return 0;
}
