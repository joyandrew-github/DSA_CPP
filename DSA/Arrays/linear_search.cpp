#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 50, 20, 70, 30};
    int target = 50;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            cout << "Found at index " << i;
            return 0;
        }
    }

    cout << "Not found";
    return 0;
}